<?php

namespace App;

use Illuminate\Support\Facades\DB;

class Movie
{

    public static function getMovies()
    {
        $pdo = DB::getPdo();
        $sql = "SELECT 
            m.idMovie as idMovie,
            CAST(s.start as DATE) as jour,
            CAST(CAST(s.start as TIME) as varchar(5)) as heure, 
            m.title as film,
            s.idRoom as salle, 
            SUM(r.capacity - s.soldTickets) as place 
            from Movie m 
            join Shows s on s.idMovie = m.idMovie
            join Room r on r.idRoom = s.idRoom
            WHERE start > now()
            GROUP BY s.start, m.title, s.idRoom
            ORDER BY s.start, m.title ASC;";
        $statement = $pdo->prepare($sql);
        $statement->execute();
        return $pdo->query($sql)->fetchAll();
    }

    public static function buyPlaces($soldPlace, $title, $salle)
    {
        $pdo = DB::getPdo();
        $sql = "UPDATE Shows s 
                INNER JOIN Movie m on m.idMovie = s.idMovie
                SET s.soldTickets = s.soldTickets+$soldPlace
                WHERE s.idRoom = $salle AND m.title = '$title';";
        $statement = $pdo->prepare($sql);
        $statement->execute();
    }

    public static function getMovie($id)
    {
        $pdo = DB::getPdo();
        $sql = "SELECT *
        from Movie 
        where idMovie = $id;";
        $statement = $pdo->prepare($sql);
        $statement->execute();
        return $pdo->query($sql)->fetchAll();
    }
}
