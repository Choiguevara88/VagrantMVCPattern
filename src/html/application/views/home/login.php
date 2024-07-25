<? // if(CH_HTTP === "http://") { location_replace("https://".$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI']); } ?>
<? // include __DIR__."/"; ?>
<?
	// $P = [3,4];
	// $O = [0,0];
	// $line = sqrt(pow(abs($P[0])-abs($O[0]),2) + pow(abs($P[1])-abs($O[1]),2));
	// abs($line);
?>
<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta http-equiv="X-UA-Compatible" content="IE=edge" />
<title>ADMINISTRATOR LOGIN</title>
<link rel="shortcut icon" href="/static/favicon_32x32.png">
<link rel="icon" 					href="/static/favicon_32x32.png">
<meta name='viewport' content='width=device-width, initial-scale=1.0'>
<link href="/css/notosans.css" rel="stylesheet" type="text/css"/>

<script src="/js/jquery-3.6.0.min.js"></script>
<style>
    * { margin:0;  padding:0;  box-sizing: border-box; font-family: 'Noto Sans KR', sans-serif; font-size:10px; }
    body { display:flex;justify-content:center;align-items:center;height:100vh;background: url("/static/images/login_background.jpg") no-repeat center;background-size:cover;margin:0;}
    input[type='checkbox']{vertical-align:middle;}
    body::before  {content:"";position: absolute;z-index:1;top:0;right:0;bottom:0;left:0;background-color: rgba(0,0,0,.5);}
    form { max-width: 44rem; width: 100%;}
    .login-form   {position:relative; z-index:2; max-width:90%; margin:0 auto;}
    .login-form h1 {font-size:3.2rem; color:#fff; text-align:center; margin-bottom:60px;}
    .login-form h1 font {font-size:3.2rem; color:#99e7ff;}
    .int-area     {max-width:40rem; position:relative; margin-top:20px;}
    .int-area:first-child {margin-top:0;}
    .int-area input {width:100%;padding:40px 10px 10px;background-color:transparent;border:none;border-bottom:1px solid #999;font-size:18px; color:#fff;outline:none;}
    .int-area label {position:absolute; left:10px; top:15px; font-size:1.8rem; color:#999;transition: all .5s ease;}
    .int-area label.warning {color:#ff1717 !important; animation:warning .5s ease; animation-iteration-count:3; -webkit-animation:warning .5s ease; -moz-animation:warning .5s ease;}
    @keyframes warning{
      0%		{transform: translateX(-8px);}
      12.5%	{transform: translateX(8px);}
      20%		{transform: translateY(10px);}
      25% 	{transform: translateX(-8px);}
      37.5% {transform: translateX(8px);}
      50% 	{transform: translateX(-8px);}
      70%		{transform: translateY(-10px);}
      75% 	{transform: translateX(8px);}
    }
    .int-area input:focus + label, .int-area input:valid + label { top:-2; font-size:13px; color:#2cb1ff;}
    .btn-area {margin-top:30px;}
    .btn-area button {width:100%;height:5rem; font-size: 1.6rem; background: linear-gradient(226deg, #98ffcf, #008bdc); color:#fff;border: none;border-radius:25px;font-family:'Noto Sans KR','sans-serif';
    transition:all ease 0.3s; -webkit-transition:all ease 0.3s; cursor: pointer;}
    .btn-area button:hover{color:#eee;}
    .caption { margin-top:20px; text-align:center;}
    .caption label { font-size:15px; color:#fff; text-decoration:none;transition:all ease .2s;-webkit-transition:all ease .2s;}
    .caption label:hover { color:#2cb1ff; }
    #save_hp {margin-left:20px;}
    .off {display:none;}
    .int-area span.timer { position: absolute; bottom: 10px; right: -15px; color: #999; font-size:13px; }
    .int-area span.warning { color:#FF1717; }
    .int-area {transition: all 1s ease;}
</style>
</head>
<body>
	<form name="frm" id="frm" action="./login.php" method="POST" autocomplete="off">
    <input type="hidden" name="mode" value="login" />
  	<section class="login-form">
  		<h1><font style="">ADMINISTRATOR</font> LOGIN</h1>
  		<div class="int-area">
  			<input type="text" name="id" id="id" value="<?=$_COOKIE['save_id']?>" required>
  			<label for="id">ADMINISTRATOR ID</label>
  		</div>
  		<div class="int-area">
  			<input type="password" name="pw" id="pw" maxlength="20" value="" required>
  			<label for="pw">PASSWORD</label>
        <span class="timer off"></span>
  		</div>
      <div class="int-area off" id="auth-area">
        <input type="tel" name="auth_num" id="auth_num" class="only_num" maxlength="6" required>
        <label for="auth_num">AUTH NUMBER</label>
      </div>
  		<div class="btn-area">
  			<button type="button" id="btn" onclick="member_login()">LOGIN</button>
  		</div>
  		<div class="caption">
  			<input type="checkbox" name="save_id" id="save_id" <?=$_COOKIE['save_id']!=""?"checked":""?> value="Y">
  			<label for="save_id">SAVE ID?</label>
  		</div>
  	</section>
	</form>
</body>

<script>
  function member_login() {
    let id  = $("#id").val();
    if(id == "")  {
      alert("아이디를 입력하세요.");
      $("#id").next("label").addClass("warning");
      setTimeout(function(){$("#id").next("label").removeClass("warning")},1000);
      return false;
    }
    let password  = $("#pw").val();
    if(password == "") {
			alert("패스워드를 입력하세요.");
      $("#pw").next("label").addClass("warning");
      setTimeout(function(){$("#pw").next("label").removeClass("warning")},1000);
      return false;
    }

		$.ajax({
			url : "/Member/LoginApi",
			type : "POST",
      data : $("#frm").serialize(),
      dataType : 'json',
			success : function(data) {
        // console.log(data);
        alert(data.msg);
				if(data.result) location.reload();
			}
		});
	}

  $(function(){
		let id	= $("#id");
		let pw	= $("#pw");
		let btn	= $("#btn");

		$(btn).on("click", function() {
			if($(id).val() == "")	{
				$(id).next("label").addClass("warning");
				setTimeout(function(){$('label').removeClass("warning")},1000)
			}
			else if($(pw).val() == "")	{
				$(pw).next("label").addClass("warning");
				setTimeout(function(){$('label').removeClass("warning")},1000)
			}
		});

    $(id).on("keydown", function(key){
      if(key.code == "Enter")  $(pw).focus();
    });
    $(pw).on("keydown", function(key){
      if(key.code == "Enter")  member_login();
    })

	});
</script>

</html>
