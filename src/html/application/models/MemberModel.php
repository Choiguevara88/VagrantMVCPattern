<?php

namespace application\models;

class MemberModel extends Model {
  public $idx, $id, $name, $photo, $icon, $nick, $email, $tphone, $hphone, $homepage, $post, $address1, $address2, $reemail, $resms, $birthday, $level, $level_str, $visit, $visit_time, $intro, $memo, $addinfo1, $addinfo2, $addinfo3, $addinfo4, $addinfo5, $sex, $sns, $snskey, $latitude, $longitude, $appToken;

  function __construct($id) {
    parent::__construct();
    $this->id = $id;
  }

  // 회원정보 조회
  public function info() {

    $sql  = sprintf("SELECT * FROM ch_member WHERE id='%s'", sql_escape_string($this->id));
    $res  = $this->pdo->query($sql);
    $row  = $res->fetch();

    if($row['idx'] != "") {

      $this->idx        = $row['idx'];
      $this->id         = $row['id'];
      $this->name       = $row['name'];
      $this->photo      = $row['photo'];
      $this->icon       = $row['icon'];
      $this->email      = $row['email'];
      $this->thpone     = $row['tphone'];
      $this->hphone     = $row['hphone'];
      $this->homepage   = $row['homepage'];
      $this->post       = $row['post'];
      $this->address1   = $row['address1'];
      $this->address2   = $row['address2'];
      $this->reemail    = $row['reemail'];
      $this->resms      = $row['resms'];
      $this->birthday   = $row['birthday'];
      $this->level      = $row['level'];
      $this->visit      = $row['visit'];
      $this->visit_time = $row['visit_time'];
      $this->intro      = $row['intro'];
      $this->memo       = $row['memo'];
      $this->addinfo1   = $row['addinfo1'];
      $this->addinfo2   = $row['addinfo2'];
      $this->addinfo3   = $row['addinfo3'];
      $this->addinfo4   = $row['addinfo4'];
      $this->addinfo5   = $row['addinfo5'];
      $this->sex        = $row['sex'];
      $this->sns        = $row['sns'];
      $this->snskey     = $row['snskey'];
      $this->latitude   = $row['latitude'];
      $this->longitude  = $row['longitude'];
      $this->appToken   = $row['appToken'];

      return true;
    } else {
      return "회원 정보에 접근할 수 없습니다.";
    }
  }
  // 회원 ID 유무체크
  function id_check($_id) {
    $sql  = "SELECT * FROM ch_member WHERE id = :id";
    $sql  = sprintf("SELECT * FROM ch_member WHERE id='%s'", sql_escape_string($_id));
    $res  = $this->pdo->query($sql);
    $row  = $res->fetch();

    if($row['idx'] == "") return true;
    else                  return false;
  }

  // 회원 가입
  public function join($form) {

    global $util;

    $id_check = $this->id_check($form['id']);
    if(!$id_check)  return "이미 존재하는 아이디입니다.";

    $sql  = "INSERT INTO ch_member SET ";
    $not_insert_array = ['photo','icon'];
    $form['passwd'] = hash('sha256', $form['passwd']);
    foreach($form AS $key => $val) {
      if(in_array($key, $not_insert_array)) continue;
      $sql .= "{$key} = '{$val}', ";
    }

    if($_FILES['photo']['size'] > 0 && $util->file_check($_FILES['photo']['name'])) {
      $photo_name = $util->file_upload("photo", CH_DATA_PATH."/member", "{$form['id']}_photo");
      $sql .= "photo = '{$photo_name}', ";
    }

    if($_FILES['icon']['size'] > 0 && $util->file_check($_FILES['icon']['name'])) {
      $icon_name = $util->file_upload("icon", CH_DATA_PATH."/member", "{$form['id']}_icon");
      $sql .= "icon = '{$icon_name}', ";
    }

    if($form['address1'] != "") {
      list($_lat, $_lng) = $util->kakao_location_API($form['address1']);
      $sql .= "latitude = '{$_lat}', longitude = '{$_lng}', ";
    }

    $sql  .= "wid = '{$form['id']}', wdate = NOW(), mid = '{$form['id']}', ip='{$_SERVER['REMOTE_ADDR']}'";

    try {
      $this->pdo->exec($sql);
      return true;
    } catch(PDOException $e) {
      return "{$e->getMessage()}\n{$e->getFile()} - Line({$e->getLine()})\n{$sql}";
    }
  }

  // 회원로그인
  public function login($id, $passwd) {

    $sql  = sprintf("SELECT * FROM ch_member WHERE id='%s'", sql_escape_string($id));
    $res  = $this->pdo->query($sql);
    $row  = $res->fetch();

    if($row['idx'] == "")                         return "존재하지 않는 아이디입니다.";
    if(hash('sha256', $passwd) != $row['passwd']) return "비밀번호가 맞지 않습니다.";

    $this->info();

    $today  = date('Y-m-d');
    $sql    = "UPDATE ch_member SET
               visit      = visit+1,
               visit_time = NOW()
               WHERE  id = '{$id}'
               AND    visit_time <= '{$today} 00:00:00'";
    try {
      $this->pdo->exec($sql);
      return true;
    } catch(PDOException $e) {
      return "{$e->getMessage()}\n{$e->getFile()} - Line({$e->getLine()})\n{$sql}";
    }
  }
}

?>
