<!DOCTYPE html>
<html lang='ko'>
<head>
    <meta charset='UTF-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <link href='/css/ch_style.css' rel='stylesheet' type='text/css'/>
    <link rel='stylesheet' type='text/css' href='https://unpkg.com/boxicons@2.0.9/css/boxicons.min.css'>
    <title><?=$err_msg?></title>
</head>
<body>
  <section class='errorWrap'>
    <div class='errorBox'>
    <i class='bx bx-error-circle'></i>
    <p><strong><?=$err_key?></strong></p>
    <p><?=$err_msg?></p>
    </div>
  </section>
</body>
</html>
