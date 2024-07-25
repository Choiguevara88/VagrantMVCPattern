
  </div> <!-- END home-content -->
  <div class="footer">
    <p><?=$site_info['admin_copyright']?></p>
  </div>
</section> <!-- END home-section -->

<script>
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
            let date = new Date();
            date.setTime(date.getTime() + 60 * 60 * 24);
            let no = e.target.getAttribute('data-cookie');
            if(showChk)  document.cookie = 'sidebar'+no+'=Y;expires=' + date.toUTCString() + ';path=/';
            else         document.cookie = 'sidebar'+no+'=N;expires=' + date.toUTCString() + ';path=/';
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
        let date = new Date();
        date.setTime(date.getTime() + (1000 * 60 * 60 * 24));
        let no = e.target.getAttribute('data-cookie');
        if(showChk)  document.cookie = 'sidebar'+no+'=Y;expires=' + date.toUTCString() + ';path=/';
        else         document.cookie = 'sidebar'+no+'=N;expires=' + date.toUTCString() + ';path=/';

      })
    }

    let sidebar = document.querySelector(".sidebar");
    let sidebarBtn = document.querySelector(".bx-menu-alt-left");

    sidebarBtn.addEventListener("click", () => {
        sidebar.classList.toggle("close");
        let closeChk = false;
        for(var i = 0; i < sidebar.classList.length; ++i) {
          if(sidebar.classList[i] == 'close') {
            closeChk = true;
            break;
          }
        }
        let date = new Date();
        date.setTime(date.getTime() + (1000 * 60 * 60 * 24));
        if(closeChk)  document.cookie = 'sidebarClose=Y;expires=' + date.toUTCString() + ';path=/';
        else          document.cookie = 'sidebarClose=N;expires=' + date.toUTCString() + ';path=/';
    });
    const admLogout = () => {
      if(confirm("정말 로그아웃 하시겠습니까?")) {
        location.href= "../../logout.php";
      }
    }
    $(function(){

      $("#allChk").on("click", function(){
  			if($("#allChk").is(":checked"))	$("input[name='sel_idx[]']").prop("checked", true);
  			else							$("input[name='sel_idx[]']").prop("checked", false);
  		});

      $("input[type='tel']").on("input", function(){ $(this).val( $(this).val().replace(/[^0-9.\-]/g,"") ); });

    });
</script>
</body>
</html>

<? sql_close(); ?>
