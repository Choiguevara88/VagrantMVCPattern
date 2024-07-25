<style>
  .modal_outter { position: fixed; top: 0; height: 100vh; width: calc(100% - 24rem); background: rgba(0,0,0,.4); z-index: 998; display:none; }
  .modal_outter.show { display: flex; align-items: center; justify-content: center; }
  .sidebar.close ~ .home-section .modal_outter { width : calc(100% - 78px); }
  .modal_outter .modal_container { background: #FFF; display: flex; flex-direction: column; padding:3rem; z-index: 999; border-radius: 1.2rem; box-shadow:0 10px 15px rgba(0,0,0,.3); min-width:300px; max-width:100%; margin:3rem; }
  .modal_outter .modal_container .modal_header { display:flex; justify-content: space-between; align-items: center; margin-bottom:1.6rem; }
  .modal_outter .modal_container .modal_header h1 { font-size:2rem; letter-spacing: -0.05rem; }
  .modal_outter .modal_container .modal_header h1 {}
  .modal_outter .modal_container .modal_header button i.bx { font-size:2.6rem; color:#AAA; }
  .modal_outter .modal_container .profile_box { display:flex; width:100%; margin:1rem 0rem; gap:1.4rem; }
  .modal_outter .modal_container .profile_box .image_box { flex-direction: column; align-items: center; }
  .modal_outter .modal_container .profile_box .image_box img { width:80px; height:80px; object-fit:cover; }
  .modal_outter .modal_container .profile_box .image_box p { text-align:center; font-size:1.1rem; }
  .modal_outter .modal_container .profile_box .text_box { flex-direction: column; }
  .modal_outter .modal_container .profile_box .text_box h1 { font-size:1.6rem; font-weight:400; }
  .modal_outter .modal_container .profile_box .text_box h2 { font-size:1.3rem; font-weight:300; max-width:50rem; }
  .modal_outter .modal_container .form_box { flex-direction: column; }
  .modal_outter .modal_container .modal_footer { margin-top:1rem;text-align: center; font-size:1.4rem; }
</style>
<?php $modal_id = "ddd"; ?>
<button onclick="document.querySelector('#<?=$modal_id?>').classList.toggle('show')">toggle</button>
<div class="modal_outter show" id="<?=$modal_id?>">
  <div class="modal_container">
    <div class="modal_header">
      <h1>Modal's Subject</h1>
      <button type="button" onclick="document.querySelector('#<?=$modal_id?>').classList.toggle('show')">
        <i class='bx bx-exit'></i>
      </button>
    </div>

    <div class="profile_box">
      <div class="image_box">
        <img src="/static/images/test_profile2.jpg" />
        <p>Profile Name</p>
      </div>
      <div class="text_box">
        <h1>Infomation Title</h1>
        <h2>Information sub information</h2>
      </div>
    </div>

    <div class="form_box">
      <form id="modalForm<?=$modal_id?>">
        <div class="inputBox">
          <label>파일이있습니다.</label>
          <input type="text" name="" id="modal" placeholder="" />
        </div>
        <div class="inputBox">
          <label>처음부터그거였습니까?</label>
          <textarea name="" id="" ></textarea>
        </div>
        <div class="inputBox">
          <div class="btnBox">
            <button>This is Footer</button>
          </div>
        </div>
      </form>
    </div>
    <div class="modal_footer">

    </div>
  </div>
</div>
