<div class="pageTitle">
  <h1><i class='bx bx-cog'></i> 사이트정보<small>사이트 기본정보를 관리합니다.</small></h1>
</div>

<form name="frm" action="siteInfo/save/" method="post" enctype="multipart/form-data" onSubmit="return inputCheck(this);">
<input type="hidden" name="tmp">
<input type="hidden" name="mode" value="site_info">

<section class="cardWrapper">

	<div class="cardContainer">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>사이트정보</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label for="site_name">사이트명</label>
          <input name="site_name" id="site_name" type="text" value="<?=$site_info['site_name']?>">
        </div>
        <div class="inputBox">
          <label for="site_url">사이트 URL</label>
          <input name="site_url" id="site_url" type="text" value="<?=$site_info['site_url']?>">
        </div>
      </div>
    </div>

    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>관리자정보</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label for="site_email">관리자 이메일</label>
          <input name="site_email" id="site_email" type="email" value="<?=$site_info['site_email']?>">
        </div>
				<div class="rowBox">
					<div class="inputBox">
	          <label for="site_tel">관리자 전화번호</label>
	          <input name="site_tel" id="site_tel" type="tel" value="<?=$site_info['site_tel']?>" placeholder="02-1234-5678">
	        </div>
					<div class="inputBox">
	          <label for="site_hand">관리자 휴대폰</label>
	          <input name="site_hand" id="site_hand" type="tel" value="<?=$site_info['site_hand']?>" placeholder="010-1234-5678">
	        </div>
				</div>
      </div>
    </div>
  </div>
  <div class="cardContainer top20">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>메타태그정보</h3>
      <div class="cardContent">
        <div class="rowBox">
          <div class="inputBox">
            <label for="site_title">사이트 Title</label>
            <input name="site_title" id="site_title" type="text" value="<?=$site_info['site_title']?>">
          </div>
          <div class="inputBox">
            <label for="site_keyword">검색 키워드</label>
            <input name="site_keyword" id="site_keyword" type="text" value="<?=$site_info['site_keyword']?>">
          </div>
        </div>
        <div class="inputBox">
          <label for="site_description">소개글</label>
          <input name="site_description" id="site_description" type="text" value="<?=$site_info['site_description']?>">
        </div>
      </div>
    </div>
  </div>

  <div class="cardContainer top20">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>네이버 웹마스터도구</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label for="naver_key">HTML태그 (메타태그)</label>
          <input name="naver_key" id="naver_key" type="text" value="<?=$site_info['naver_key']?>">
        </div>
        <p class="subInfo">
          <i class="bx bxs-info-circle"></i>
          &lt;meta name="naver-site-verification" content="<b>{ 내용 입력 }</b>"/&gt;
        </p>
      </div>
    </div>
  </div>

  <div class="cardContainer top20">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>FTP정보</h3>
      <div class="cardContent">
        <div class="inputBox">
          <label for="ftp_host">접속주소 (IP, 도메인)</label>
          <input name="ftp_host" id="ftp_host" type="text" value="<?=$site_info['ftp_host']?>">
        </div>
        <div class="rowBox">
          <div class="inputBox">
            <label for="ftp_id">아이디</label>
            <input name="ftp_id" id="ftp_id" type="text" value="<?=$site_info['ftp_id']?>">
          </div>
          <div class="inputBox">
            <label for="ftp_pw">비밀번호</label>
            <input name="ftp_pw" id="ftp_pw" type="text" value="<?=$site_info['ftp_pw']?>">
          </div>
        </div>
        <p class="subInfo">
          <i class="bx bxs-info-circle"></i>
          사이트 운영에 영향을 미치는 것이 아니며, 분실하기 쉬운 정보를 작성하여 사이트 관리에 이용함이 목적입니다.
        </p>
      </div>
    </div>
  </div>

  <div class="cardContainer top20">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>도메인정보</h3>
      <div class="tableBox">
        <div class="subInfo">
          <div></div>
          <div><button type="button"onClick="inputDomain('insert','');">도메인등록</button></div>
        </div>
        <table border="0" cellpadding="0" cellspacing="0" class="rwd-table">
        <thead>
        <tr>
          <th>NO</th>
        	<th>도메인</th>
        	<th>구입사이트</th>
        	<th>아이디</th>
        	<th>비밀번호</th>
        	<th>만료일</th>
        	<th>기능</th>
        </tr>
        </thead>
        <tbody>
          <tr>
            <td data-th="NO"><?=$no?></td>
            <td data-th="도메인"><?=$row['info01']?></td>
            <td data-th="구입사이트"><?=$row['info02']?></td>
            <td data-th="아이디"><?=$row['info03']?></td>
            <td data-th="비밀번호"><?=$row['info04']?></td>
            <td data-th="만료일"><?=$row['info05']?></td>
            <td data-th="기능">
              <button type="button" onclick="inputDomain('update','<?=$row[idx]?>')">수정</buttom>
              <button type="button" onclick="inputDomain('delete','<?=$row[idx]?>')">삭제</buttom>
            </td>
          </tr>
          <?php if($total <= 0) : ?>
          <tr><td colspan="20" class="empty">등록된 도메인이 없습니다.</td></tr>
          <?php endif; ?>
        </tbody>
        </table>
        <p class="subInfo" style="justify-content:flex-start;">
          <i class="bx bxs-info-circle"></i>
          사이트 운영에 영향을 미치는 것이 아니며, 분실하기 쉬운 정보를 작성하여 사이트 관리에 이용함이 목적입니다.
        </p>
      </div>
    </div>
  </div>

  <div class="cardContainer top20">
    <div class="cardBox">
      <h3><i class='bx bxs-caret-right-square'></i>사업자정보</h3>
      <div class="cardContent">

        <div class="rowBox">
          <div class="inputBox">
            <label for="com_num">사업자등록번호</label>
            <input name="com_num" id="com_num" type="text" value="<?=$site_info['com_num']?>">
          </div>
          <div class="inputBox">
            <label for="com_seal">인감</label>
            <div class="rowBox">
              <input name="com_seal_name" id="com_seal_name" type="text" value="<?=$site_info['com_seal']?>" placeholder="인감 파일을 선택하세요." readonly>
              <input name="com_seal" id="com_seal" type="file">
              <?php if(is_file(__DIR__."../../../data/config/com_seal.gif")) : ?>
                <img src='/adm/data/config/com_seal.gif'>
              <?php endif; ?>
            </div>
          </div>
        </div>

        <div class="rowBox">
          <div class="inputBox">
            <label for="com_name">상호</label>
            <input name="com_name" id="com_name" type="text" value="<?=$site_info['com_name']?>">
          </div>
          <div class="inputBox">
            <label for="com_owner">대표자명</label>
            <input name="com_owner" id="com_owner" type="text" value="<?=$site_info['com_owner']?>">
          </div>
        </div>

        <div class="inputBox">
          <label for="com_post1">주소</label>
          <div class="rowBox">
            <input name="com_post1" id="com_post1" type="text" maxlength="5" value="<?=$site_info['com_post']?>" readonly onclick="javascript:searchZip()" style="flex:1" placeholder="우편번호 검색">
            <input name="com_address1" id="com_address" type="text" value="<?=$site_info['com_address']?>" style="flex:4">
          </div>
        </div>

        <div class="rowBox">
          <div class="inputBox">
            <label for="com_kind">업태</label>
            <input name="com_kind" id="com_kind" type="text" value="<?=$site_info['com_kind']?>">
          </div>
          <div class="inputBox">
            <label for="com_class">종목</label>
            <input name="com_class" id="com_class" type="text" value="<?=$site_info['com_class']?>">
          </div>
        </div>

        <div class="rowBox">
          <div class="inputBox">
            <label for="com_tel">전화번호</label>
            <input name="com_tel" id="com_tel" type="text" value="<?=$site_info['com_kind']?>">
          </div>
          <div class="inputBox">
            <label for="com_fax">팩스번호</label>
            <input name="com_fax" id="com_fax" type="text" value="<?=$site_info['com_fax']?>">
          </div>
        </div>

      </div>
    </div>
  </div>


	<footer>
    <button type="submit" class="">확인</button>
  </footer>
</section>
</form>

<script src="//t1.daumcdn.net/mapjsapi/bundle/postcode/prod/postcode.v2.js"></script>
<script language="javascript">
	function inputCheck(frm){
		if(frm.site_name.value == "")	{alert("사이트명을 입력하세요.");frm.site_name.focus();return false;}
		if(frm.site_url.value == "")	{alert("사이트 URL을 입력하세요.");frm.site_url.focus();return false;}
		if(frm.site_email.value == "")	{alert("관리자 이메일을 입력하세요.");frm.site_email.focus();return false;}
		if(frm.site_hand.value == "")	{alert("관리자 휴대폰을 입력하세요.");frm.site_hand.focus();return false;}
	}

function inputDomain(submode,idx){
   if(submode == "delete"){
      if(confirm("삭제하시겠습니까?")){
         document.location = "site_save.php?mode=domain&submode=delete&idx=" + idx;
      }
   }else{
	   var url = "./domain_input.php?submode=" + submode + "&idx=" + idx;
	   window.open(url,"inputDomain","height=550, width=550, menubar=no, scrollbars=yes, resizable=yes, toolbar=no, status=no, top=100, left=100");
   }
}

function inputEmail(submode,idx){
   if(submode == "delete"){
      if(confirm("삭제하시겠습니까?")){
         document.location = "site_save.php?mode=email&submode=delete&idx=" + idx;
      }
   }else{
	   var url = "./email_input.php?submode=" + submode + "&idx=" + idx;
	   window.open(url,"inputEmail","height=550, width=550, menubar=no, scrollbars=yes, resizable=no, toolbar=no, status=no, top=100, left=100");
   }
}

function searchZip() {
	var kind		= 'com_';
	var themeObj	= { searchBgColor: "#0B65C8", queryTextColor: "#FFFFFF" };
	new daum.Postcode({
		theme : themeObj, animation : true,
		oncomplete	: function(data) {
			var extraAddr = "";
			eval('document.frm.'+kind+'post1').value = data.zonecode;
			if (data.userSelectedType === 'R')	eval('document.frm.'+kind+'address1').value = data.roadAddress;		// 사용자가 도로명 주소를 선택했을 경우
			else								eval('document.frm.'+kind+'address1').value = data.jibunAddress;	// 사용자가 지번 주소를 선택했을 경우(J)
	        if(data.userSelectedType === 'R'){
				if(data.bname !== '')			extraAddr += data.bname;														// 법정동명이 있을 경우 추가한다.
				if(data.buildingName !== '')	extraAddr += (extraAddr !== '' ? ', ' + data.buildingName : data.buildingName);	// 건물명이 있을 경우 추가한다.
				extraAddr = (extraAddr !== '' ? ' ('+ extraAddr +')' : '');														// 조합형주소의 유무에 따라 양쪽에 괄호를 추가하여 최종 주소를 만든다.
			}
			if(eval('document.frm.'+kind+'address2') != null) {
				eval('document.frm.'+kind+'address2').focus();
				eval('document.frm.'+kind+'address2').value	= extraAddr;
			}
		}
	}).open();
}

    function checkFileImg(str){
        let ext =  str.split('.').pop().toLowerCase();
        if($.inArray(ext, ['jpg', 'jpeg', 'gif', 'bmp', 'png']) == -1) {
            return 1;
        }
        let pattern =   /[\{\}\/?,;:|*~`!^\+<>@\#$%&\\\=\'\"]/gi;
        if(pattern.test(str) ){
            return 2;
        }
        return 0;
    }

    const maxSize  = 104857600;
    const showSize = "100";

    $(function(){
      $('#com_seal').on('change', function() {

        let filename = $(this)[0].files[0].name;
        let fileSize = this.files[0].size;
        let nameCheck = checkFileImg(filename);

        if(nameCheck === 1) { alert("이미지만 첨부가능합니다.(jpg, jpeg, gif, bmp, png)"); return false; }
        if(nameCheck === 2) { alert("파일명에 허용된 특수문자는 '-', '_', '(', ')', '[', ']', '.' 입니다."); return false;}

        if(fileSize > maxSize) {
          alert("첨부파일 사이즈는 "+ showSize +"MB 이내로 등록 가능합니다.");
          return false;
        } else {
          $(this).siblings('#com_seal_name').val(filename);
        }
      });

      $("#com_seal_name").on('click', function(e) {
        $('#com_seal').trigger('click');
      });
    });

</script>
