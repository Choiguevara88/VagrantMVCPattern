<!DOCTYPE html>
<html lang='ko'>
<head>
    <meta charset='UTF-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <link href='/css/ch_style.css' rel='stylesheet' type='text/css'/>
    <link rel='stylesheet' type='text/css' href='https://unpkg.com/boxicons@2.0.9/css/boxicons.min.css'>
    <title><?=$com_msg?></title>
</head>
<body>
  <section class='completeWrap'>
    <div class='completeBox'>
    <i class='bx bx-check-circle'></i>
    <p><?=$com_msg?></p>
    </div>
  </section>
</body>
<script>
  <? if($go_url != "") { ?>
  window.setTimeout(()=>{document.location='<?=$go_url?>'},1200);
  <? } else { ?>
  window.setTimeout(()=>{history.go(-1)},1200);
  <? } ?>
</script>
</html>
