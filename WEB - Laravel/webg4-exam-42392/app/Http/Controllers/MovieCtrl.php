<?php

namespace App\Http\Controllers;

use \App\Movie;
use Illuminate\Http\Request;

class MovieCtrl extends Controller
{

    public function listAll()
    {
        $movie = Movie::getMovies();
        return view('movie', ['movies' => $movie]);
    }

    public function buyPlaces()
    {
        $ticketing= $_POST['ticketing'];
        $title = $_POST['title'];
        $room = $_POST['room'];
        Movie::buyPlaces($ticketing, $title, $room);
        return redirect()->action('MovieCtrl@listAll');
    }

    public function movieJSON($id){
        $movie = Movie::getMovie($id);
        $sfon = json_encode($movie);
        return $sfon;
    }

}
