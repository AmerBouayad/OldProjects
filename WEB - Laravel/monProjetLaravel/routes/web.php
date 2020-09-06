<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});

Route::get('/hello/{name}', 'HelloCtrl@index');

Route::get('/', 'TodoCtrl@listAll');

Route::get('/todo/{id}','TodoCtrl@detail');

Route::get('/todo/json/{id?}','TodoCtrl@todoDetailJSON');

Route::get('/json','TodoCtrl@todoJSON');



    