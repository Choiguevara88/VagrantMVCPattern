
  </div> <!-- END home-content -->
  <div class="footer">
    <p><?=$site_info['admin_copyright']?></p>
  </div>
</section> <!-- END home-section -->

<script>
  const cookieDate = new Date();
  cookieDate.setTime(cookieDate.getTime() + (1000 * 60 * 60 * 24));

  let arrow = document.querySelectorAll(".arrow");

  for(var i=0; i < arrow.length; i++) {
      arrow[i].addEventListener("click", (e) => {
          let arrowParent = e.target.parentElement.parentElement;
          arrowParent.classList.toggle("showMenu");
          let showChk = false;
          for(var j = 0; j < arrowParent.classList.length; ++i) {
            if(arrowParent.classList[j] == 'showMenu') {
              showChk = true;
              break;
            }
          }
          let no = e.target.getAttribute('data-cookie');
          if(showChk)  document.cookie = 'sidebar'+no+'=Y;expires=' + cookieDate.toUTCString() + ';path=/';
          else         document.cookie = 'sidebar'+no+'=N;expires=' + cookieDate.toUTCString() + ';path=/';
      });
  }

  let linkName = document.querySelectorAll(".haveArrow");

  for(var i=0; i < linkName.length; i++) {
    linkName[i].addEventListener("click", (e)=>{
      let arrowParent = e.target.parentElement.parentElement.parentElement;
      arrowParent.classList.toggle("showMenu");

      let showChk = false;
      for(var j = 0; j < arrowParent.classList.length; ++i) {
        if(arrowParent.classList[j] == 'showMenu') {
          showChk = true;
          break;
        }
      }
      let no = e.target.getAttribute('data-cookie');
      if(showChk)  document.cookie = 'sidebar'+no+'=Y;expires=' + cookieDate.toUTCString() + ';path=/';
      else         document.cookie = 'sidebar'+no+'=N;expires=' + cookieDate.toUTCString() + ';path=/';

    })
  }

  let sidebar = document.querySelector(".sidebar");
  let sidebarBtn = document.querySelector(".bx-menu");

  sidebarBtn.addEventListener("click", () => {
      sidebar.classList.toggle("close");
      let closeChk = false;
      for(var i = 0; i < sidebar.classList.length; ++i) {
        if(sidebar.classList[i] == 'close') {
          closeChk = true;
          break;
        }
      }
      if(closeChk)  document.cookie = 'sidebarClose=Y;expires=' + cookieDate.toUTCString() + ';path=/';
      else          document.cookie = 'sidebarClose=N;expires=' + cookieDate.toUTCString() + ';path=/';
  });

  const admLogout = () => {
    if(confirm("정말 로그아웃 하시겠습니까?")) {
      location.href= "../../logout.php";
    }
  }

  const autoCloseMenu = () => {
    let closeChk = true;
    for(var i = 0; i < sidebar.classList.length; ++i) {
      if(sidebar.classList[i] == 'close') { closeChk = false; break; }
    }
    if(closeChk) {
      document.cookie = 'sidebarClose=Y;expires=' + cookieDate.toUTCString() + ';path=/';
      document.querySelector(".sidebar").classList.add("close");
    }
  }

  $(function(){
    $("#allChk").on("click", function(){
			if($("#allChk").is(":checked"))	$("input[name='sel_idx[]']").prop("checked", true);
			else							              $("input[name='sel_idx[]']").prop("checked", false);
		});
    $("input[type='tel']").on("input", function(){ $(this).val( $(this).val().replace(/[^0-9.\-]/g,"") ); })

    if($(window).width() <= 500)  autoCloseMenu();
    $(window).resize(function() {
      if($(window).width() <= 500)autoCloseMenu();
    });
  });
</script>
</body>
</html>
