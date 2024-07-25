<!DOCTYPE HTML>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name='viewport' content='width=device-width, initial-scale=1.0'>
  <title><?=$site_info['admin_title']?></title>
  <script src="/js/jquery-3.6.0.min.js"></script>
  <link href="/css/ch_style.css" rel="stylesheet" type="text/css"/>
  <link rel='stylesheet' type="text/css" href='https://unpkg.com/boxicons@2.0.9/css/boxicons.min.css'>
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link rel="shortcut icon" href="/static/favicon_32x32.png">
  <link rel="icon" 					href="/static/favicon_32x32.png">
</head>
<body>
    <div class="sidebar <?=$_COOKIE['sidebarClose'] == "Y" ? "close" : ""?>">
        <div class="logo-details">
            <a href="javascript:void(0)"><i class='bx bx-menu'></i></a>
            <a href="/Home/" class="logo_name">ADMINISTRATOR</a>
        </div>
        <ul class="nav-links">
            <li class="<?=$_COOKIE['sidebarBasic'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="javascript:void(0)">
                        <i class='bx bx-cog'></i>
                        <span class="link_name haveArrow" data-cookie="Basic">기본설정</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="Basic"></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="javascript:void(0)">기본설정</a></li>
                    <li><a href="/config">환경설정</a></li>
                    <li><a href="/siteInfo">사이트정보</a></li>
                    <li><a href="../basic/admin_list.php">관리자설정</a></li>
                    <li><a href="../basic/popup_list.php">팝업관리</a></li>

                </ul>
            </li>

            <li class="<?=$_COOKIE['sidebarHospital'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="javascript:void(0)">
                        <i class='bx bx-buildings'></i>
                        <span class="link_name haveArrow" data-cookie="Hospital">병원관리</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="Hospital"></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="javascript:void(0)">병원관리</a></li>
                    <li><a href="../hospital/hospital_list.php">병원설정</a></li>
                    <li><a href="../hospital/member_list.php">병원관리자설정</a></li>
                    <li><a href="../hospital/company_list.php">사업장설정</a></li>
                    <li><a href="../hospital/membership_list.php">회원권설정</a></li>
                    <li><a href="../hospital/reserve_list.php">예약설정</a></li>
                    <li><a href="../hospital/bbs_list.php">병원게시글설정</a></li>
                    <li><a href="../hospital/banner.php">배너설정</a></li>
                    <li><a href="../hospital/slide.php">슬라이드설정</a></li>
                </ul>
            </li>

            <li class="<?=$_COOKIE['sidebarBBS'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="javascript:void(0)">
                        <i class='bx bx-collection'></i>
                        <span class="link_name haveArrow" data-cookie="BBS">게시판관리</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="BBS"></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="javascript:void(0)">게시판관리</a></li>

                    <li><a href="../bbs/bbs_list.php">게시판관리</a></li>
                    <li><a href="../bbs/bbs_manage_list.php">게시물통합관리</a></li>
                    <li><a href="../bbs/bbs_manage_comment.php">코멘트통합관리</a></li>

                </ul>
            </li>


            <li class="<?=$_COOKIE['sidebarBBSList'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="#">
                        <i class='bx bx-book-alt'></i>
                        <span class="link_name haveArrow" data-cookie="BBSList">게시물관리</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="BBSList"></i>
                </div>
                <ul class="sub-menu">
                  <li><a class="link_name haveArrow" href="#">게시물관리</a></li>
                  <li><a href="../bbs/bbs_manage_list.php">게시물통합관리</a></li>
                  <?php foreach($site_info['bbs'] AS $bbs): ?>
                    <? if((strcmp($bbs['grp'], $tmp_grp) || strcmp($bbs['grp'], $tmp_first)) && $site_info['bbs_grp_list'][$bbs['grp']] != "") { ?>
                    <li><b><?=$site_info['bbs_grp_list'][$bbs['grp']]?></b></li>
                    <? } ?>
                    <li><a href="../bbs/list.php?code=<?=$bbs['code']?>"><?=$bbs['title']?></a></li>
                    <? $tmp_first = $bbs['grp']; $tmp_grp = $bbs['grp']; ?>
                  <?php endforeach; ?>
                </ul>
            </li>


            <li class="<?=$_COOKIE['sidebarMember'] == "Y" ? "showMenu" : ""?>">
              <div class="icon-link">
                <a href="javascript:void(0)">
                  <i class='bx bxs-face'></i>
                  <span class="link_name haveArrow" data-cookie="Member">회원관리</span>
                </a>
                <i class='bx bx-chevron-down arrow' data-cookie="Member" ></i>
              </div>
              <ul class="sub-menu">
                <li><a class="link_name haveArrow" href="javascript:void(0)">회원관리</a></li>
                <li><a href="../member/member_list.php">회원설정</a></li>
              </ul>
            </li>
            <li class="<?=$_COOKIE['sidebarProduct'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="javascript:void(0)">
                      <i class='bx bx-cart-alt'></i>
                      <span class="link_name haveArrow" data-cookie="Product">쇼핑몰관리</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="Product"></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="javascript:void(0)">쇼핑몰관리</a></li>
                    <li><a href="../product/shop_oper.php">운영정보설정</a></li>
                    <li><a href="../product/prd_list.php">상품목록</a></li>
                    <li><a href="../product/prd_category.php">상품분류</a></li>
                    <li><a href="../product/prd_brand.php">브랜드관리</a></li>
                    <li><a href="../product/prd_option.php">옵션항목</a></li>
                    <li><a href="../product/prd_shortage.php">재고관리</a></li>
                    <li><a href="../product/order_list.php">주문관리</a></li>
                    <li><a href="../product/cancel_list.php">개별취소요청</a></li>
                    <? /*
                    <li><a href="../product/prd_estimate.php">상품평관리</a></li>
                    <li><a href="../product/prd_qna.php">상품문의관리</a></li>
                    <li><a href="../product/cancel_list.php">취소요청</a></li>
                    <li><a href="../product/order_list.php?s_status=CD">교환요청</a></li>
                    <li><a href="../product/tax_list.php?tax_type=T">세금계산서</a></li>
                    <li><a href="../product/tax_list.php?tax_type=C">현금영수증</a></li>
                    <li><a href="../product/shop_coupon.php">쿠폰관리</a></li>
                    <li><a href="../product/shop_reserve.php">적립금관리</a></li>
                    */ ?>
                </ul>
            </li>
            <li class="<?=$_COOKIE['sidebarPage'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="javascript:void(0)">
                        <i class='bx bx-book-open'></i>
                        <span class="link_name haveArrow" data-cookie="Page">약관관리</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="Page"></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="javascript:void(0)">약관관리</a></li>
                <?php foreach($site_info['page'] AS $page) : ?>
                    <li><a href="../page/page_input.php?mode=update&idx=<?=$page['idx']?>"><?=$page['title']?></a></li>
                <?php endforeach; ?>
                </ul>
            </li>
            <? /*
            <li class="<?=$_COOKIE['sidebarAnalytics'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="javascript:void(0)">
                      <i class='bx bxs-pie-chart-alt-2' ></i>
                      <span class="link_name haveArrow" data-cookie="Analytics">접속통계</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="Analytics"></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="javascript:void(0)">접속통계</a></li>
                    <li><a href="../connect/connect_list.php">접속자분석</a></li>
                    <li><a href="../connect/connect_refer.php">접속경로분석</a></li>
                    <li><a href="../connect/connect_keyword.php">검색키워드분석</a></li>
                    <li><a href="../connect/connect_osbrowser.php">OS/브라우저</a></li>
                </ul>
            </li>
            */ ?>

            <li class="<?=$_COOKIE['sidebarDB'] == "Y" ? "showMenu" : ""?>">
                <div class="icon-link">
                    <a href="javascript:void(0)">
                      <i class='bx bxs-data'></i>
                      <span class="link_name haveArrow" data-cookie="DB">데이터관리</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' data-cookie="DB"></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="javascript:void(0)">데이터관리</a></li>
                    <li><a href="../db/disease_list.php">질병목록</a></li>
                    <li><a href="../db/food_list.php">식품목록</a></li>
                    <li><a href="../db/drug_list.php">의약품목록</a></li>
                </ul>
            </li>
            <? /*
            <!-- <li>
                <a href="#">
                    <i class='bx bx-line-chart' ></i>
                    <span class="link_name haveArrow">차트</span>
                </a>
                <ul class="sub-menu blank">
                    <li><a class="link_name haveArrow" href="#">차트</a></li>
                </ul>
            </li>
            <li>
                <div class="icon-link">
                    <a href="#">
                        <i class='bx bx-plug' ></i>
                        <span class="link_name haveArrow">플러그인</span>
                    </a>
                    <i class='bx bx-chevron-down arrow' ></i>
                </div>
                <ul class="sub-menu">
                    <li><a class="link_name haveArrow" href="#">플러그인</a></li>
                    <li><a href="#">UI Face</a></li>
                    <li><a href="#">Pigments</a></li>
                    <li><a href="#">Box Icons</a></li>
                </ul>
            </li>
            <li>
                <a href="#">
                    <i class='bx bx-compass' ></i>
                    <span class="link_name">Explore</span>
                </a>
                <ul class="sub-menu blank">
                    <li><a class="link_name" href="#">Explore</a></li>
                </ul>
            </li>
            <li>
                <a href="#">
                    <i class='bx bx-history' ></i>
                    <span class="link_name">History</span>
                </a>
                <ul class="sub-menu blank">
                    <li><a class="link_name" href="#">History</a></li>
                </ul>
            </li>
            <li>
                <a href="#">
                    <i class='bx bx-cog' ></i>
                    <span class="link_name">Setting</span>
                </a>
                <ul class="sub-menu blank">
                    <li><a class="link_name" href="#">Setting</a></li>
                </ul>
            </li> -->
            */?>
            <li>
                <div class="profile-details">
                    <div class="profile-content">
                        <img src="/static/favicon_32x32.png" alt="profile">
                    </div>

                    <div class="name-job">
                        <div class="profile_name"><?=$_SESSION['ch_admin']['id']?></div>
                        <div class="job"><?=$_SESSION['ch_admin']['name']?></div>
                    </div>
                    <i class='bx bx-log-out' onclick="javascript:admLogout()"></i>
                </div>
            </li>
        </ul>
    </div>
    <section class="home-section">
        <div class="home-content">
