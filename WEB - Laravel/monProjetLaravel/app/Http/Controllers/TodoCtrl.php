<?php

namespace App\Http\Controllers;

use \App\Todo;
use Illuminate\Http\Request;

class TodoCtrl extends Controller
{

    public function listAll()
    {
        $todos = Todo::all();
        return view('todo', ['todos' => $todos]);
    }

    public function detail($id){
        $todo = Todo::find($id);
        return view('detail', ['todo' => $todo]);
    }

    public function todoDetailJSON($id){
        $todo = Todo::find($id);
        $sfon = json_encode($todo);
        return $sfon;
    }

    public function todoJSON(){
        $todos = Todo::all();
        $sfon = json_encode($todos);
        return $sfon;    
    }
}
