<div class="pageTitle">
  <i class='bx bx-home-circle'></i> <h1><?=$site_info['site_name']?> <small>DASHBOARD</small></h1>
</div>
<section class="cardWrapper">
  <div class="cardContainer">
    <div class="cardContent">
      <h2>회원현황 <a href="">더 보기 <i class='bx bxs-right-arrow-square'></i></a></h2>
      <?php if(count($admin_main['member']) == 0) : ?>
        <div class="emptyCard">
          <i class='bx bx-male-female'></i>
          등록된 회원이 없습니다.
        </div>
      <?php else : ?>
        <ul class="mainCard">
        <?php foreach($admin_main['member'] AS $member): ?>
          <li>
            <span class="flex2 overHidden"><a href=""><?=$member['id']?></a></span>
            <span class="txtCt overHidden"><?=$member['name']?></span>
            <span class="level txtCt overHidden"><?=$member['lv']?></span>
            <span class="short right"><?=str_replace("-",".",substr($member['wdate'],2,8))?></span>
          </li>
        <?php endforeach; ?>
        </ul>
      <?php endif; ?>
       <div class="cardFooter">
         <div>
           <p>오늘 가입회원</p>
           <span><strong><?=$admin_main['today_total']?></strong> 명</span>
         </div>
         <div>
           <p>이달 가입회원</p>
           <span><strong><?=$admin_main['month_total']?></strong> 명</span>
         </div>
         <div>
           <p>올해 가입회원</p>
           <span><strong><?=$admin_main['year_total']?></strong> 명</span>
         </div>
         <div>
           <p>전체 회원수</p>
           <span><strong><?=$admin_main['all_total']?></strong> 명</span>
         </div>
       </div><!-- END cardFooter -->
     </div>

     <div class="cardContent">
       <h2>게시판현황 <a href="">더 보기 <i class='bx bxs-right-arrow-square'></i></a></h2>
       <?php if(count($admin_main['bbs']) == 0) : ?>
         <div class="emptyCard">
           <i class='bx bx-loader'></i>
           등록된 게시글이 없습니다.
         </div>
       <?php else : ?>
       <ul class="mainCard">
         <?php foreach($admin_main['bbs'] AS $bbs): ?>
         <li>
           <span class="category"><?=$bbs['title']?></span>
           <span class="subject">
             <a href="<?=$bbs['url']?>"><?=$bbs['subject']?><?=$bbs['new']?></a>
           </span>
           <span class="short right"><?=str_replace("-",".",substr($bbs['wdate'],2,8))?></span>
         </li>
        <?php endforeach; ?>
       </ul>
      <?php endif; ?>
       <div class="cardFooter">
         <div>
           <p>총 게시판수</p>
           <span><strong style="color:#ffff9b;"><?=$admin_main['bbs_num']?></strong> 개</span>
         </div>
         <div>
           <p>총 게시물</p>
           <span><strong style="color:#ffff9b;"><?=$admin_main['bbs_total']?></strong> 개</span>
         </div>
         <div>
           <p>오늘 게시물</p>
           <span><strong style="color:#ffff9b;"><?=$admin_main['bbs_today']?></strong> 개</span>
         </div>
         <div>
           <p>오늘 댓글</p>
           <span><strong style="color:#ffff9b;"><?=$admin_main['cmt_today']?></strong> 개</span>
         </div>
       </div><!-- END cardFooter -->
     </div>

     <div class="cardContent">
       <h2>주문현황 <a href="">더 보기 <i class='bx bxs-right-arrow-square'></i></a></h2>
       <?php if(count($admin_main['order']) == 0) : ?>
         <div class="emptyCard order">
           <i class='bx bx-cart' ></i>
           등록된 주문이 없습니다.
         </div>
       <?php else : ?>
       <ul class="mainCard order">
         <li>
           <span class="head">주문번호</span>
           <span class="head center">주문자명</span>
           <span class="head center">주문금액</span>
           <span class="short head right">주문일자</span>
         </li>
         <?php foreach($admin_main['order'] AS $order): ?>
         <li>
           <span class="orderid"><a href="#"><?=$order['orderid']?></a></span>
           <span class="center"><?=$order['send_name']?></span>
           <span class="right"><b><?=number_format($order['total_price'])?></b> 원</span>
           <span class="short right"><?=str_replace("-",".",substr($order['order_date'],2,8))?></span>
         </li>
         <?php endforeach; ?>
       </ul>
      <?php endif; ?>
       <div class="cardFooter orderFooter">
         <div>
           <p>오늘 매출액</p>
           <span><strong style="color:#e0ffc5;"><?=$admin_main['today_price']?></strong> 원</span>
         </div>
         <div>
           <p>이달 매출액</p>
           <span><strong style="color:#e0ffc5;"><?=$admin_main['month_price']?></strong> 원</span>
         </div>
         <div>
           <p>올해 매출액</p>
           <span><strong style="color:#e0ffc5;"><?=$admin_main['year_price']?></strong> 원</span>
         </div>
         <div>
           <p>총 매출</p>
           <span><strong style="color:#e0ffc5;"><?=$admin_main['total_price']?></strong> 원</span>
         </div>
       </div><!-- END cardFooter -->
     </div>
   </div>
</section>

<section class="cardWrapper">
 <div class="cardContainer">
   <div class="cardContent chartCard">
     <h2>게시판통계 (<?=date('y.m')?>월)</h2>
     <div>
     <?php
      $chart_id     = "bbsChart";
      $chart_type   = "bar";
      $chart_max    = $admin_main['bbs_max'];
      $chart_color  = "blue";
      $chart_label  = "게시글수";
      $chart_labels = $admin_main['bbs_labels'];
      $chart_datas  = $admin_main['bbs_datas'];
      $sub_chart    = true;
      $sub_color    = "green";
      $sub_label    = "코멘트수";
      $sub_datas    = $admin_main['cmt_datas'];
      include __DIR__."/../../inc/chart.inc";
     ?>
     </div>
   </div>
   <div class="cardContent chartCard">
     <h2>접속통계 (<?=date('y.m')?>월)</h2>
     <div>
     <?php
     $chart_id     = "conChart";
     $chart_type   = "line";
     $chart_max    = $admin_main['con_max'];
     $chart_color  = "purple";
     $chart_label  = "방문자수";
     $chart_labels = $admin_main['con_labels'];
     $chart_datas  = $admin_main['con_datas'];
     include __DIR__."/../../inc/chart.inc";
     ?>
     </div>
   </div>
 </div>
</section>
