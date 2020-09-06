@extends('canevas')
@section('title', 'Acceuil')
@section('content')

<h1 class="text-primary text-center">Liste des scéances</h1>

@if (count($movies) === 0)
La liste est vide!
@else
<div class="d-flex justify-content-between">
    <table class="table table-hover">
        <thead class="bg-primary text-white">
            <tr>
                <th scope="col">Jour</th>
                <th scope="col">Heure</th>
                <th scope="col">Film</th>
                <th scope="col">Salle</th>
                <th scope="col">Places disponibles</th>
                <th scope="col">Billeterie</th>
            </tr>
        </thead>
        <tbody>
            @foreach ($movies as $movie)
            <tr>
                <td>{{$movie['jour']}}</td>
                <td>{{$movie['heure']}}</td>
                <td onclick="showInfo({{$movie['idMovie']}})">{{$movie['film']}}</td>
                <td>{{$movie['salle']}}</td>
                <td>{{$movie['place']}}</td>
                <td>
                    <form id="form" action="./buyPlaces" method="post">
                        {{csrf_field()}}
                        <input id="ticketing" name="ticketing" type=number min=0 value=0>
                        <input id="title" name="title" value="{{$movie['film']}}" type="hidden">
                        <input id="room" name="room" value="{{$movie['salle']}}" type="hidden">
                        <button class="bg-primary text-white" type="submit">Acheter</button>
                    </form>
                </td>
            </tr>
            @endforeach
        </tbody>
    </table>

    <div class="col-sm " id="answer">
        <div class="card ">
            <div id="titre" class="card-header"></div>
            <div class="card-body">
                <h5 class="card-title" id="sumary"></h5>
                <p class="card-text" id="rating"></p>
            </div>
        </div>
    </div>
</div>

</div>

@section('scripts')
<script>
    function showInfo(idMovie) {
        $.get("movie/" + idMovie, function(jsData, status) {
            var fck=JSON.parse(jsData);
            console.log(fck)
            $("#answer").show();
            $("#titre").text(fck[0].title);
            $("#sumary").text(fck[0].summary);
            $("#rating").text(fck[0].rating);
    });
}
</script>
@endsection

@endif
@endsection