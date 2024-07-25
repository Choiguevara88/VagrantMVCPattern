<div class="pageTitle">
  <h1><i class='bx bx-cog'></i> 환경설정<small>사이트운영에 필요한 기본정보를 설정합니다.</small></h1>
</div>
<form name="frm" action="/config/save/" method="post" enctype="multipart/form-data" onSubmit="return inputCheck(this)">
<section class="cardWrapper">

  <div class="cardContainer">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>관리자 타이틀</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label for="admin_title">관리자 타이틀</label>
          <input name="admin_title" id="admin_title" type="text" value="<?=$site_info['admin_title']?>">
        </div>
        <div class="inputBox">
          <label for="admin_copyright">관리자 카피라잇</label>
          <input name="admin_copyright" id="admin_copyright" type="text" value="<?=$site_info['admin_copyright']?>">
        </div>
      </div>
    </div>
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>디자이너 아이디 비밀번호</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label for="designer_id">디자이너 아이디</label>
          <input name="designer_id" id="designer_id" type="text" value="<?=$site_info['designer_id']?>" readonly onCLick="idCheck()">
        </div>
        <div class="inputBox">
          <label for="designer_pw">디자이너 비밀번호</label>
          <input name="designer_pw" id="designer_pw" type="password">
        </div>
      </div>
    </div>
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>메뉴 사용여부</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label >메뉴 선택</label>
          <div class="chkBox">
            <label><input type="checkbox" name="menu_use[]" value="BASIC"   <? if($site_info['menu_arr']["BASIC"]==true) echo "checked";?>> 기본설정</label>
            <label><input type="checkbox" name="menu_use[]" value="BBS"     <? if($site_info['menu_arr']["BBS"]==true) echo "checked";?>> 게시판관리</label>
            <label><input type="checkbox" name="menu_use[]" value="MEMBER"  <? if($site_info['menu_arr']["MEMBER"]==true) echo "checked";?>> 회원관리</label>
            <label><input type="checkbox" name="menu_use[]" value="FORMMAIL"<? if($site_info['menu_arr']["FORMMAIL"]==true) echo "checked";?>> 폼메일관리</label>
            <label><input type="checkbox" name="menu_use[]" value="POLL"    <? if($site_info['menu_arr']["POLL"]==true) echo "checked";?>> 설문관리</label>
            <label><input type="checkbox" name="menu_use[]" value="SCHEGUAL"<? if($site_info['menu_arr']["SCHEGUAL"]==true) echo "checked";?>> 스케쥴관리</label>
            <label><input type="checkbox" name="menu_use[]" value="PAGE"    <? if($site_info['menu_arr']["PAGE"]==true) echo "checked";?>> 페이지관리</label>
            <label><input type="checkbox" name="menu_use[]" value="BANNER"  <? if($site_info['menu_arr']["BANNER"]==true) echo "checked";?>> 배너관리</label>
            <label><input type="checkbox" name="menu_use[]" value="LOG"     <? if($site_info['menu_arr']["LOG"]==true) echo "checked";?>> 접속통계</label>
            <label><input type="checkbox" name="menu_use[]" value="PRODUCT" <? if($site_info['menu_arr']["PRODUCT"]==true) echo "checked";?>> 쇼핑몰관리</label>
          </div>
        </div>
        <p class="subInfo"><i class='bx bxs-info-circle' ></i> 사용여부에 따라 메뉴을 보이거나 숨길 수 있습니다.</p>
      </div>
    </div>
  </div>

  <div class="cardContainer top15">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>게시판/설문/스케쥴/페이지/배너 생성기능 설정</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label >사용여부</label>
          <div class="chkBox">
            <label><input type="radio" name="addbbs_use" value="Y" <? if(!strcmp($site_info['addbbs_use'], "Y") || empty($site_info['addbbs_use'])) echo "checked" ?>> 사용</label>
          	<label><input type="radio" name="addbbs_use" value="N" <? if(!strcmp($site_info['addbbs_use'], "N")) echo "checked" ?>> 사용안함</label>
          </div>
        </div>
        <p class="subInfo"><i class='bx bxs-info-circle' ></i> 사용여부에 따라 메뉴을 보이거나 숨길 수 있습니다.</p>
      </div>
    </div>
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>견적서 사용여부</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label >사용여부</label>
          <div class="chkBox">
            <label><input type="radio" name="estimate_use" value="Y" <? if(!strcmp($site_info['estimate_use'], "Y") || empty($site_info['estimate_use'])) echo "checked" ?>> 사용</label>
          	<label><input type="radio" name="estimate_use" value="N" <? if(!strcmp($site_info['estimate_use'], "N")) echo "checked" ?>> 사용안함</label>
          </div>
        </div>
        <p class="subInfo"><i class='bx bxs-info-circle' ></i> "견적서"를 사용하는 경우 장바구니에서 견적서를 출력할 수 있습니다.</p>
      </div>
    </div>
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>쪽지 사용여부</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label >사용여부</label>
          <div class="chkBox">
            <label><input type="radio" name="msg_use" value="Y" <? if($site_info['msg_use'] == "Y") echo "checked"; ?>>사용함</label>
            <label><input type="radio" name="msg_use" value="N" <? if($site_info['msg_use'] == "N") echo "checked"; ?>>사용안함</label>
          </div>
        </div>
      </div>
    </div>
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>포인트 사용여부</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label >사용여부</label>
          <div class="chkBox">
            <label><input type="radio" name="point_use" value="Y" <?php if($site_info['point_use'] == "Y") echo "checked"; ?>>사용함</label>
            <label><input type="radio" name="point_use" value="N" <?php if($site_info['point_use'] == "N") echo "checked"; ?>>사용안함</label>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="cardContainer top15">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>SSL 사용여부</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label >사용여부</label>
          <div class="chkBox">
            <label><input type="radio" name="ssl_use" value="Y" <? if($site_info['ssl_use'] == "Y") echo "checked"; ?>>사용함</label>
          	<label><input type="radio" name="ssl_use" value="N" <? if($site_info['ssl_use'] == "N") echo "checked"; ?>>사용안함</label>
          </div>
        </div>
        <div class="inputBox">
          <label for="ssl_port">포트번호</label>
          <input type="text" name="ssl_port" id="ssl_port" value="<?=$site_info['ssl_port']?>" class="input">
        </div>
        <p class="subInfo">
          <i class='bx bxs-info-circle' ></i> SSL을 사용하는 경우 기본적으로 서버에 SSL이 적용이 되어있어야합니다.
        </p>
        <p class="subInfo">
          <i class='bx bxs-info-circle' ></i> 확인 방법 https://해당도메인 ex) https://<?=$HTTP_HOST?>
        </p>
      </div>
    </div>
  </div>
  <footer>
    <button type="submit" class="">확인</button>
  </footer>
</section>

</form>


<script language="javascript">
  function inputCheck(frm) {
  	if(frm.designer_id.value == ""){ alert("디자이너 아이디를 입력하세요."); frm.designer_id.focus(); return false; }
  }
  // 아이디 중복확인
  function idCheck() {
     var id	= document.frm.designer_id.value;
     var url	= "../member/id_check.php?name=designer_id&id=" + id;
     window.open(url, "idCheck", "width=430, height=320, menubar=no, scrollbars=no, resizable=no, toolbar=no, status=no");
  }
</script>
