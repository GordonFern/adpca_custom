<?php
function log_it($str) {

  echo "What the heck is going on and why can't I see anything";

  $file='/home/adpca/gash.txt';
  $fh=fopen($file,'a') or die("Can't open file");
  fwrite($fh,$str . "\n");
  fclose($fh);
}
?>
