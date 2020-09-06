@extends('canevas')
@section('title', 'Detail')
@section('content')
        <h1>Tâche : {{$todo->name}}</h1>
        <p>{{$todo->description}}</p>
        <a href="/todo/json/{{$todo->id}}">Version JSON</a><br>
        <a href="/">Retour à la liste</a>
@endsection