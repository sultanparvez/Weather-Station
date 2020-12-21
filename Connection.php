<?php
//Creates new record as per request
 //Connect to database
 $servername = "localhost";
 $username = "bracuweather_data";
 $password = "bracuweatherdata";
 $dbname = "bracuweather_data";
 // Create connection
 $conn = new mysqli($servername, $username, $password, $dbname);
 // Check connection
 if ($conn->connect_error) {
 die("Database Connection failed: " . $conn->connect_error);
 }
 //Get current date and time
 date_default_timezone_set('Asia/Dhaka');
 $d = date("Y-m-d");
 //echo " Date:".$d."<BR>";
 $t = date("H:i:s");
 if(!empty($_GET['data']))
 {
 $data = $_GET['data'];
print($data);
 $sql = "INSERT INTO data (date, time, data)
VALUES ('".$d."', '".$t."', '".$data."')";
if ($conn->query($sql) === TRUE) {
 echo "OK";
} else {
 echo "Error: " . $sql . "<br>" . $conn->error;
}
}
?>
