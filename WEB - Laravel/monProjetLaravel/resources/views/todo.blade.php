@extends('canevas')
@section('title', 'TODO')
@section('content')
<h1>A faire</h1>
@if(count($todos) === 0)
<p>Rien pour le moment ;)</p>
@else
<ul>
    @foreach ($todos as $todo)
    <li>
        <a href="/todo/{{$todo->id}}">{{$todo->name}}</a>
    </li>
    @endforeach
</ul>
<a href="/json">Version JSON</a>
@endif
@endsection