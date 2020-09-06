<!doctype html>
<html lang="fr">

<head>
    <title>@yield('title')</title>
    <div class="p-3 bg-primary text-white text-center">
        <div id="header">
            <img src="/image/logo.jpg" width="100" />
            <h1 th:text="#{title}">WEB II - Cinéma</h1>
        </div>
        <p>HE2B-ESI / WEBG4 / NRI / août 2020</p>
    </div>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="{{ asset('css/style.css') }}">
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.8/jquery.min.js"></script>
</head>

<body>
    <main>@yield('content')</main>
    @yield('scripts')
</body>

<footer class="page-footer font-small bg-primary">

    <!-- Copyright -->
    <div class="footer-copyright text-center py-3 text-white">© 2020 Copyright: Bouayad Amer</div>
    <!-- Copyright -->

</footer>

</html>