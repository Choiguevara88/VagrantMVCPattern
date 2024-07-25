<?php include_once __DIR__."/chart_config.inc"; ?>
<canvas id="<?=$chart_id?>"></canvas>
<script>
  let chartData<?=$chart_id?> = {
    labels: [<?=$chart_labels?>],
    datasets: [{
      label: '<?=$chart_label?>',
      backgroundColor: color(chartColors.<?=$chart_color?>).alpha(1).rgbString(),
      borderColor: chartColors.<?=$chart_color?>,
      borderWidth: 1,
      data: [<?=$chart_datas?>]
    }
    <?php if($sub_chart) : ?>
    , {
      label: '<?=$sub_label?>',
      backgroundColor: color(chartColors.<?=$sub_color?>).alpha(1).rgbString(),
      borderColor: chartColors.<?=$sub_color?>,
      borderWidth: 1,
      data: [<?=$sub_datas?>]
    }
    <?php endif; ?>
  ]
  };
  let config<?=$chart_id?> = {
    type    : '<?=$chart_type?>',
    data    : chartData<?=$chart_id?>,
    options : {
      responsive: true,
      plugins: {
        legend: { position: 'bottom' },
      },
      scales: {
      <?php if($chart_max) : ?>
        // yAxes: [{
        //   ticks: { min: 0, max: <?=$chart_max?> }
        // }],
      <?php endif; ?>
      }
		}
  };
  $(function() {
    let ctx = document.getElementById('<?=$chart_id?>');
    let myChart<?=$chart_id?> = new Chart(ctx, config<?=$chart_id?>);
  });
</script>
<?php
unset($chart_id);
unset($chart_type);
unset($chart_max);
unset($chart_color);
unset($chart_label);
unset($chart_labels);
unset($chart_datas);
unset($sub_chart);
unset($sub_color);
unset($sub_label);
unset($sub_datas);
?>
