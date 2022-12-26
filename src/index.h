const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
  <title>Band Selector</title>
  <script>
    var State1;
    var State2;
    var State3;
    var State4;
    var State5;
    var State6;
    var State7;
    var State8;
    function DisplayCurrentTime() {
      var dt = new Date();
      var weekday = new Array(7);
      weekday[0] = "Sunday";
      weekday[1] = "Monday";
      weekday[2] = "Tuesday";
      weekday[3] = "Wednesday";
      weekday[4] = "Thursday";
      weekday[5] = "Friday";
      weekday[6] = "Saturday";
      var dow = weekday[dt.getDay()];
      document.getElementById("datetime").innerHTML = (dow) + " " + (dt.toLocaleString());
      setTimeout('DisplayCurrentTime()', 1000);
    };
    function GetState() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          State1 = this.responseXML.getElementsByTagName("analog")[0].childNodes[0].nodeValue;
          State2 = this.responseXML.getElementsByTagName("analog")[1].childNodes[0].nodeValue;
          State3 = this.responseXML.getElementsByTagName("analog")[2].childNodes[0].nodeValue;
          State4 = this.responseXML.getElementsByTagName("analog")[3].childNodes[0].nodeValue;
          State5 = this.responseXML.getElementsByTagName("analog")[4].childNodes[0].nodeValue;
          State6 = this.responseXML.getElementsByTagName("analog")[5].childNodes[0].nodeValue;
          State7 = this.responseXML.getElementsByTagName("analog")[6].childNodes[0].nodeValue;
          State8 = this.responseXML.getElementsByTagName("analog")[7].childNodes[0].nodeValue;
        }
        if (State1 != 0) {
          var codeBlock1 = '<button type="submit" class="button-on">Relay1 On</button>';
          document.getElementById("statled1").innerHTML = codeBlock1;
        } else {
          var codeBlock1 = '<button type="submit" class="button-off">Relay1 Off</button>';
          document.getElementById("statled1").innerHTML = codeBlock1;
        }
        if (State2 != 0) {
          var codeBlock2 = '<button type="submit" class="button-on">Relay2 On</button>';
          document.getElementById("statled2").innerHTML = codeBlock2;
        } else {
          var codeBlock2 = '<button type="submit" class="button-off">Relay2 Off</button>';
          document.getElementById("statled2").innerHTML = codeBlock2;
        }
        if (State3 != 0) {
          var codeBlock3 = '<button type="submit" class="button-on">Relay3 On</button>';
          document.getElementById("statled3").innerHTML = codeBlock3;
        } else {
          var codeBlock3 = '<button type="submit" class="button-off">Relay3 Off</button>';
          document.getElementById("statled3").innerHTML = codeBlock3;
        }
        if (State4 != 0) {
          var codeBlock4 = '<button type="submit" class="button-on">Relay4 On</button>';
          document.getElementById("statled4").innerHTML = codeBlock4;
        } else {
          var codeBlock4 = '<button type="submit" class="button-off">Relay4 Off</button>';
          document.getElementById("statled4").innerHTML = codeBlock4;
        }
        if (State5 != 0) {
          var codeBlock5 = '<button type="submit" class="button-on">Relay5 On</button>';
          document.getElementById("statled5").innerHTML = codeBlock5;
        } else {
          var codeBlock5 = '<button type="submit" class="button-off">Relay5 Off</button>';
          document.getElementById("statled5").innerHTML = codeBlock5;
        }
        if (State6 != 0) {
          var codeBlock6 = '<button type="submit" class="button-on">Relay6 On</button>';
          document.getElementById("statled6").innerHTML = codeBlock6;
        } else {
          var codeBlock6 = '<button type="submit" class="button-off">Relay6 Off</button>';
          document.getElementById("statled6").innerHTML = codeBlock6;
        }
        if (State7 != 0) {
          var codeBlock7 = '<button type="submit" class="button-on">Relay7 ON</button>';
          document.getElementById("statled7").innerHTML = codeBlock7;
        } else {
          var codeBlock7 = '<button type="submit" class="button-off">Relay7 OFF</button>';
          document.getElementById("statled7").innerHTML = codeBlock7;
        }
        if (State8 != 0) {
          var codeBlock8 = '<button type="submit" class="button-on">Relay8 ON</button>';
          document.getElementById("statled8").innerHTML = codeBlock8;
        } else {
          var codeBlock8 = '<button type="submit" class="button-off">Relay8 OFF</button>';
          document.getElementById("statled8").innerHTML = codeBlock8;
        }
      }
      xhttp.open("GET", "redstate", true);
      xhttp.send();
      setTimeout('GetState()', 2000);
    };
    document.addEventListener('DOMContentLoaded', function () {
      DisplayCurrentTime(), GetState();
    }, false);
  </script>
  <style>
    body {
      text-align: center;
      background-color: #ffaaaa;
    }

    /* Full-width input fields */
    input[type=text],
    input[type=password] {
      width: 100%;
      padding: 12px 20px;
      margin: 8px 0;
      display: inline-block;
      border: 1px solid #ccc;
      box-sizing: border-box;
    }

    .container {
      padding: 16px;
    }

    span.psw {
      float: right;
      padding-top: 16px;
    }

    /* The Modal (background) */
    .modal {
      display: none;
      /* Hidden by default */
      position: fixed;
      /* Stay in place */
      z-index: 1;
      /* Sit on top */
      left: 0;
      top: 0;
      width: 100%;
      /* Full width */
      height: 100%;
      /* Full height */
      overflow: auto;
      /* Enable scroll if needed */
      background-color: rgb(0, 0, 0);
      /* Fallback color */
      background-color: rgba(0, 0, 0, 0.4);
      /* Black w/ opacity */
      padding-top: 60px;
    }

    /* Set a style for all buttons */
    button {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #000000;
      width: 100%;
      border: #fbfb00 solid 3px;
      background-color: #0000ff;
      color: white;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 600;
      -moz-border-radius: 10px;
      -webkit-border-radius: 10px;
    }

    button:hover {
      text-shadow: 2px 2px #ff0000;
      opacity: 0.8;
    }

    .button-on {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #ffffff;
      width: 80%;
      border: #fbfb00 solid 3px;
      background-color: #00ff00;
      color: #000000;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      -moz-border-radius: 12px;
      -webkit-border-radius: 12px;
    }

    .button-on:hover {
      text-shadow: 2px 2px #444400;
      opacity: 0.8;
    }

    .button-on-latch {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #ffffff;
      width: 80%;
      border: #fbfb00 solid 3px;
      background-color: #00FF00;
      color: #000000;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      animation: blinkingBackground 1s infinite;
      -moz-border-radius: 12px;
      -webkit-border-radius: 12px;
    }

    @keyframes blinkingBackground {
      0% {
        background-color: #008000;
      }

      50% {
        background-color: #32CD32;
      }

      100% {
        background-color: #00FF00;
      }
    }

    .button-on-latch:hover {
      text-shadow: 2px 2px #444400;
      opacity: 0.8;
    }

    .button-off {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #000000;
      width: 80%;
      border: #fbfb00 solid 3px;
      background-color: #ff0000;
      color: #ffffff;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      -moz-border-radius: 12px;
      -webkit-border-radius: 12px;
    }

    .button-off:hover {
      text-shadow: 2px 2px #ffffff;
      opacity: 0.8;
    }

    .button-home {
      background-color: #BA55D3;
    }

    /* Modal Content/Box */
    .modal-content {
      background-color: #fefefe;
      margin: 5% auto 15% auto;
      /* 5% from the top, 15% from the bottom and centered */
      border: 1px solid #888;
      width: 40%;
      /* Could be more or less, depending on screen size */
    }

    /* Add Zoom Animation */
    .animate {
      -webkit-animation: animatezoom 0.6s;
      animation: animatezoom 0.6s
    }

    @-webkit-keyframes animatezoom {
      from {
        -webkit-transform: scale(0)
      }

      to {
        -webkit-transform: scale(1)
      }
    }

    @keyframes animatezoom {
      from {
        transform: scale(0)
      }

      to {
        transform: scale(1)
      }
    }

    /* Change styles for span and cancel button on extra small screens */
    @media screen and (max-width: 300px) {
      span.psw {
        display: block;
        float: none;
      }

      .cancelbtn {
        width: 100%;
      }
    }

    .data-input {
      text-align: center;
      background-color: #bbbbff;
      font-size: 15px;
      color: red;
      border: 5px solid #444444;
      -moz-border-radius: 7px;
      -webkit-border-radius: 7px;
    }

    table {
      text-align: center;
      border: 2px solid #ff00ff;
      background-color: #ffffff;
      width: 100%;
      color: #0000ff;
      -moz-border-radius: 7px;
      -webkit-border-radius: 7px;
    }

    td {
      border: 2px solid #00ffff;
      background-color: #111111;
      padding: 5px;
      -moz-border-radius: 9px;
      -webkit-border-radius: 9px;
    }

    .dtime {
      padding: 5px 5px 5px 5px;
      width: 100%;
      border: #fbfb00 solid 3px;
      background-color: red;
      color: #ffffff;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      -moz-border-radius: 7px;
      -webkit-border-radius: 7px;
    }
  </style>
</head>

<body>
  <table>
    <tr>
      <td>
        <form action="/LED1" method="POST">
          <span id="statled1"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED2" method="POST">
          <span id="statled2"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED3" method="POST">
          <span id="statled3"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED4" method="POST">
          <span id="statled4"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td>
        <form action="/LED5" method="POST">
          <span id="statled5"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED6" method="POST">
          <span id="statled6"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED7" method="POST">
          <span id="statled7"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED8" method="POST">
          <span id="statled8"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <!--
  <form action="/allon" method="POST">
      <button type="submit" class="button">All Relay ON</button>
  </form></td>
  -->
        <form action="/" method="POST">
          <button type="submit" class="button-home">Home</button>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/alloff" method="POST">
          <button type="submit" class="button">All Relay OFF</button>
        </form>
      </td>
    </tr>
  </table>
  <table>
    <tr>
      <td style='width:30%'>
        <div class="slidecontainer">
          <button onclick="document.getElementById('id01').style.display='block'" class="button"
            style="width:90%">Connect to Wi-Fi</button>
        </div>
        <div id="id01" class="modal">
          <form class="modal-content animate" action="/Mywifi" method="POST">
            <div class="data-input">
              <div class="slidecontainer">
                <label for="usname"><b>Wifi Ssid</b></label>
                <input type="text" placeholder="Enter Ssid" name="usname" required>
                <label for="pssw"><b>Password</b></label>
                <input type="password" placeholder="Enter Password" name="pssw">
                <button type="submit" class="button"><b>Connect</b></button>
              </div>
            </div>
          </form>
        </div>

        <script>
          // Get the modal
          var modal = document.getElementById('id01');

          // When the user clicks anywhere outside of the modal, close it
          window.onclick = function (event) {
            if (event.target == modal) {
              modal.style.display = "none";
            }
          }
        </script>
      </td>
      <td style='width:40%'>
        <b class="dtime"><span id="datetime"></span></b>
      </td>
      <td style='width:30%'>
        <form action="/restesp" method="POST">
          <button type="submit" name="rerset" class="button">Restart ESP</button>
        </form>
      </td>
    </tr>
  </table>
</body>

</html>
)=====";