#define HTML_ERROR "<!DOCTYPE html>\
<html>\
<head>\
    <link rel=\"icon\" href=\"data:image/png;base64,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\" type=\"image/x-icon\">\
    <title>Simple Light ESP32 + STM32 Server</title>\
</head>\
<body> ERROR\
</body>\
</html>"

#define HTML_OK "<!DOCTYPE html>\
<html>\
<head>\
    <link rel=\"icon\" href=\"data:image/png;base64,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\" type=\"image/x-icon\">\
    <title>Simple Light ESP32 + STM32 Server</title>\
</head>\
<body> OK\
</body>\
</html>"

#define HTML_PAGE "<!DOCTYPE html>\
<html>\
<head>\
    <link rel=\"icon\" href=\"data:image/png;base64,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\" type=\"image/x-icon\">\
    <title>Simple Light ESP32 + STM32 Server</title>\
    <style>\
        fieldset {\
            width: 500px;\
            border: 4px solid lightgrey;\
            margin: 0 auto;\
            background-color: #f7f7f7;\
            padding: 20px;\
            border-radius: 10px 10px 10px 10px;\
            margin-top: 40px;\
        }\
        fieldset fieldset {\
            width: 50%;\
            margin-top: 0px;\
            background-color: #f5f5f5;\
        }\
        legend {\
            text-align:left;\
        }\
        body {\
            background-color: #f5f5f5;\
            margin: 0 auto;\
            font-family: sans-serif;\
            cursor: default;\
        }\
        .light {\
            text-align: left;\
        }\
        .ctrlbutton {\
            width: 25px;\
            height: 25px;\
            float: right;\
            margin-right: 10px;\
            border-radius: 12px;\
        }\
        .ctrlbuttonmain {\
            width: 33px;\
            height: 33px;\
            border-radius: 16px;\
            margin-top: -4px;\
            font-size: 20px;\
            font-weight: bold;\
        }\
        .onlevelstring {\
             margin-right: 4px;\
        }\
        .currlevel {\
            text-align: center;\
            font-size: 20px;\
            font-weight: bold;\
        }\
        .setlightlevbtn {\
            margin: 0 auto;\
            display: block;\
        }\
        .currlevfield {\
            height: 80px;\
        }\
        .setlevfield {\
            margin-top: 10px;\
            height: 120px;\
        }\
        .setleveldata {\
            color: black;\
        }\
        .imgcredits {\
            border: 1px solid lightgrey;\
        }\
        button {\
            border: 2px outset lightgrey;\
            border-radius: 8px 8px 8px 8px;\
            cursor: pointer;\
            background-color: #e0e0e0;\
            color: black;\
        }\
        form input {\
            border: 2px outset lightgrey;\
            border-radius: 8px 8px 8px 8px;\
        }\
        input[type=\"file\"] {\
            border: 2px outset lightgrey;\
            border-radius: 8px 8px 8px 8px;\
        }\
        fieldset div {\
            border: 4px solid lightgrey;\
            border-radius: 10px 10px 10px 10px;\
            text-align:center;\
            float:left;\
            padding: 50px;\
            height: 200px;\
            margin-left: 10px;\
        }\
        fieldset div div {\
            border: none;\
            margin: 0 auto;\
            margin-top: 50px;\
            width: 60px;\
            padding: 0px;\
            height: 80px;\
        }\
        img {\
            border-radius: 8px 8px 8px 8px;\
            position: relative;\
        }\
        .imgoff {\
            display: none;\
        }\
        .imgon {\
            display: none;\
        }\
        .credits {\
            text-align: center;\
            width: 500px;\
            border: none;\
            margin: 0 auto;\
            margin-top: 40px;\
        }\
        \
        input[type=file]::-ms-browse {\
            border: 2px outset lightgrey;\
            border-radius: 5px;\
            cursor: pointer;\
        }\
        input[type=file]::-webkit-file-upload-button {\
            border: 2px outset lightgrey;\
            border-radius: 5px;\
            cursor: pointer;\
        }\
        input[type=file]::file-selector-button {\
            border: 2px outset lightgrey;\
            border-radius: 5px;\
            cursor: pointer;\
        }\
        input[type=file]::-ms-browse:hover {\
            border: 2px outset lightgrey;\
            border-radius: 5px;\
            cursor: pointer;\
        }\
        input[type=file]::-webkit-file-upload-button:hover {\
            border: 2px outset lightgrey;\
            border-radius: 5px;\
            cursor: pointer;\
        }\
        input[type=file]::file-selector-button:hover {\
            border: 2px outset lightgrey;\
            border-radius: 5px;\
            cursor: pointer;\
        }\
        \
        html{text-align:center}\
        h2{background-color:black;border:none;padding:16px 40px;text-decoration:none;font-size:30px;cursor:pointer;color:yellow}\
    </style>\
    <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js\"></script>\
    <script>\
        function setdownofflevel() {\
            let setofflevel = document.getElementById('setofflevel');\
            let setonlevel = document.getElementById('setonlevel');\
            if (setofflevel.innerText != '...') {\
                if (parseInt(setofflevel.innerText)-2 > setonlevel.innerText) setofflevel.innerText--;\
                if (parseInt(setofflevel.innerText)-2 == setonlevel.innerText && setonlevel.innerText > 0) {\
                    setofflevel.innerText--;\
                    setonlevel.innerText--;\
                }\
                setonlevel.style.color = \"green\"; \
                setofflevel.style.color = \"green\"; \
            }\
        }\
        function setupofflevel() {\
            let setofflevel = document.getElementById('setofflevel');\
            let setonlevel = document.getElementById('setonlevel');\
            if (setofflevel.innerText != '...') {\
                if (setofflevel.innerText < 40)\
                setofflevel.innerText++;\
                setonlevel.style.color = \"green\"; \
                setofflevel.style.color = \"green\"; \
            }\
        }\
        function setdownonlevel() {\
            let setofflevel = document.getElementById('setofflevel');\
            let setonlevel = document.getElementById('setonlevel');\
            if (setonlevel.innerText != '...') {\
                if (setonlevel.innerText > 0)\
                setonlevel.innerText--;\
                setonlevel.style.color = \"green\"; \
                setofflevel.style.color = \"green\"; \
            }\
        }\
        function setuponlevel() {\
            let setofflevel = document.getElementById('setofflevel');\
            let setonlevel = document.getElementById('setonlevel');\
            if (setonlevel.innerText != '...') {\
                if (parseInt(setonlevel.innerText)+2 < setofflevel.innerText) setonlevel.innerText++;\
                if (parseInt(setonlevel.innerText)+2 == setofflevel.innerText && setofflevel.innerText < 40) {\
                    setofflevel.innerText++;\
                    setonlevel.innerText++;\
                }\
                setonlevel.style.color = \"green\"; \
                setofflevel.style.color = \"green\"; \
            }\
        }\
        function hello0() {\
            getcurrentlevel();\
            getledstate();\
            if (document.getElementById(\"setonlevel\").style.color != \"green\") getonlevel();\
            if (document.getElementById(\"setofflevel\").style.color != \"green\") getofflevel();\
        }\
        function getcurrentlevel() {\
            $.ajax({  \
                type : \"POST\",\
                url: \"/currlightlevel\",\
                cache: false,\
                success: function(html){  \
                    $(\"#currlevel\").html(html);  \
                }\
            });  \
        }\
        function getonlevel() {\
            $.ajax({  \
                type : \"POST\",\
                url: \"/onlightlevel\",\
                cache: false,\
                success: function(html){  \
                    if (document.getElementById(\"setonlevel\").style.color != \"green\") $(\"#setonlevel\").html(html);  \
                }\
            });  \
        }\
        function getofflevel() {\
            $.ajax({  \
                type : \"POST\",\
                url: \"/offlightlevel\",\
                cache: false,\
                success: function(html){  \
                    if (document.getElementById(\"setofflevel\").style.color != \"green\") $(\"#setofflevel\").html(html);  \
                }\
            });  \
        }\
        function getledstate() {\
            $.ajax({  \
                type : \"POST\",\
                url: \"/currledstate\",\
                cache: false,\
                success: function(html){  \
                    if (html == '0') {\
                        document.getElementById(\"imgon\").style.display = \"none\";\
                        document.getElementById(\"imgoff\").style.display = \"inline\";\
                        document.getElementById(\"imgledstate\").innerText = \"-OFF-\";\
                    }\
                    if (html == 1) {\
                        document.getElementById(\"imgoff\").style.display = \"none\";\
                        document.getElementById(\"imgon\").style.display = \"inline\";\
                        document.getElementById(\"imgledstate\").innerText = \"-ON-\";\
                    }\
                }\
            });  \
        }\
        function setlightlevels() {\
            if ((document.getElementById(\"setonlevel\").innerText >= 0) && (document.getElementById(\"setofflevel\").innerText >= 0)) {\
                document.getElementById(\"setofflevel\").style.color = \"black\"; \
                document.getElementById(\"setonlevel\").style.color = \"black\"; \
                $.ajax({  \
                    type : \"POST\",\
                    url: \"/setlevels?\"+document.getElementById(\"setonlevel\").innerText+\"?\"+document.getElementById(\"setofflevel\").innerText+\"?\",\
                    cache: false,\
                });\
            } else alert(\"error\");\
        }\
        $(document).ready(function() {\
            hello0();\
            setInterval('hello0()',1000);\
        });\
    </script>\
</head>\
<body>\
    <div class=\"credits\">\
        <img class=\"imgcredits\" src=\"data:image/png;base64,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\"><h5>Simple Light ESP32 + STM32 Server</h5>\
    </div>\
    <fieldset class=\"light\">\
        <legend>Light control</legend>\
        <div>\
            <div>\
                <img class=\"imgon\" id=\"imgon\" src=\"data:image/png;base64,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\">\
                <img class=\"imgoff\" id=\"imgoff\" src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADYAAABECAYAAADKr8YXAAABb2lDQ1BpY2MAACiRdZE7SwNBFIU/EyWikRQGEUmRQsXCQFAQS42FTZAQI/hqdtc8hDyW3QQJtoKNhWAh2vgq/AfaCrYKgqAIIjb+AV+NyHonCSRIMsvs/Tgz5zJzBlzRrJGz28OQyxet+GwkuLi0HPS84cWPjz4CmmGb07FYlJbj+4E2Ve9DqlfrfU1H91rSNqCtU3jCMK2i8JRwdKNoKt4R9hsZbU34WHjUkgMK3yhdr/Kr4nSVPxVbifgMuFTPYLqB9QY2MlZOeER4MJctGbXzqJt4k/mFeakDMgPYxJklQhCdEutkKRKSmpfMmvvCFd8cBfEY8jcpY4kjTUa8o6KWpGtSakr0pHxZyir3/3naqfGxandvBDpeHOdjCDx78LvrOD8njvN7Cu5nuMrX/QXJafJL9N26NngEvi24uK5r+j5cbkP/k6lZWkVyy3SlUvB+Dj1L0HsHXSvVrGrrnD1CYlOe6BYODmFY9vtW/wDdZWf6YUxR8QAAAAlwSFlzAABcRgAAXEYBFJRDQQAAAw5JREFUaEPtWjuLwkAQnlNBEUV8gWBjI2JpZ2Fl5//1b1hYWdgIgmijKOJb75zcbQiXbDK72bz2biEceJvZ75v5Mjv7+ACAz/ejXUtpx+iHkLbEMkFFrNvtkkzPZjNSP9FOyog1Gg0ol8vm+FTAVgfsdjtYr9eiHBz7f/hNHgisVCrBYrHwDQqd02q1YL/fA9UxPC9IE2Oe9guAB0yFfUz35Oft1c9+v0/uL2LbqS+OhWNK2KGTentRdhAZYOY7SAzHFiRHIxYVKUZGgpw3sTCl5xUVASzuxAQMiUpFuj8RE5+YhK6lwXpF6vf/vbBxSypMtzhhxrUhNrfqxrVWVFUFBOEcCjabfIgaDk12bjLlYbVVHljWYKN4JIhIiNrk4bVJEQvZpJBiAbAW38wx2q7HkKD5rXilUNGUHGb/39i1jZi2xEwpJlmGTPLW1K9VxHDlrX1W1Cpi1sn9n5hoqRN1//+IRR0B0fG1jZg5QUvsAsViPcYmZ26tmKSlCkWW+kuRF9Iwlx6yYznVudpGzEYMt7XYPgJFy1H34W0T2ohhEsEzqiQ1XuJzTNtJWJ+5YXT9xuIsSQo27kQb56gRsP3B0xanvQTZuUbVewLb794HfwhKyxNNa1UiedDtq2CWLNBpEWPkknJrIJb3PKy3fGTvkUgTY5WJ6ps57ORElhDD5ZsYM6TdXSpeTRn17TdlEYtb0fx31mNx87wsHiUXMQeDAdRqNVkM5nvL5RImk4lvO2hACbHz+Qyv18s3oNPp5NuG8nSvDJEiQ9omDyVSRCcPh0MoFovwfD7JPk+lvv2KMh6Px+T3KB2VEdtsNpBOp42H2jKZjOGI6XRKfYXcL9IJulqtwuPxMG5tq27KImYFVq/XodlsQjabdcW73W5hPp+r5mTYC4RYp9OBSqUCl8uFC/p+vxtzX1DEIpViPp8HlXOX1YuhEMNvCRtKs91uG1FarVaBSJAZDUSKVsSj0Qhut5vxUy6XM/72ej04HA5wPB4DIxdKxKxJ5Hq9QqFQCJQUeisUYoGFxcWwtiXVF/MEoPlwotPzAAAAAElFTkSuQmCC\">\
            </div>\
            <h3 id=\"imgledstate\">- ON -</h3>\
        </div>\
        <fieldset class=\"currlevfield\">\
            <legend>Current light level</legend>\
            <p class=\"currlevel\" id=\"currlevel\">\
                Loading...\
            </p>\
        </fieldset>\
        <fieldset class=\"setlevfield\">\
            <legend>Settings</legend>\
            <p class=\"onlevelstring\">\
                Light <b>ON</b> level:\
                <span class=\"setleveldata\" id=\"setonlevel\">\
                    ...\
                </span>\
                <button class=\"ctrlbutton\" onclick=\"setdownonlevel()\">-</button>\
                <button class=\"ctrlbutton ctrlbuttonmain\" onclick=\"setuponlevel()\">+</button>\
            </p>\
            <p>\
                Light <b>OFF</b> level:\
                <span class=\"setleveldata\" id=\"setofflevel\">\
                    ...\
                </span>\
                <button class=\"ctrlbutton ctrlbuttonmain\" onclick=\"setdownofflevel()\">-</button>\
                <button class=\"ctrlbutton\" onclick=\"setupofflevel()\">+</button>\
            </p>\
            <button class=\"setlightlevbtn\" onclick=\"setlightlevels()\">Set settings</button>\
        </fieldset>\
    </fieldset>\
    <fieldset>\
        <legend>STM32</legend>\
        <form action=\"/flash\" method=\"post\" enctype=\"multipart/form-data\">\
            .hex firmware file :\
            <input type=\"file\" name=\"myFile\">\
            <button type=\"submit\">Flash</button>\
        </form>\
    </fieldset>\
    <div class=\"credits\">\
        <h5>&copy; 2021 by SimpleLightESP+STMServerMakerGroupInc. No rights reserved.</h5>\
    </div>\
</body>\
</html>"
