#include "htmlbuilder.h"
#include<QDebug>
HtmlBuilder::HtmlBuilder()
{
    header=tr("<!Doctype html>"
              "<html>"
              "<head>"
              "<style>"
              "html{width:100%}"
              "pre{white-space:pre-wrap;word-wrap:break-word;}"
              "body{width:100%}"
              "#main{width:100%}"
              "strong{color:#1f1f1f;font-weight:bold;}"
              "h1{font-size:32pt;}"
              "h2{font-size:28pt;}"
              "h3{font-size:24pt;} "
              "h4{font-size:20pt;}"
              "h5{font-size:16pt;} "
              "h6{font-size:14pt;}"
              "code{width:100%;color:#ddd;background:#404244}"
              "hr{border:1px solid #666;}"
              "</style>"
              "</head>");
}

void HtmlBuilder::setBody(const QString &value)
{
    body="<body>";
    body+="<div id=\"main\">";
    body += value;
    body+="</div>";
    body+="</body>";
}

QString HtmlBuilder::getHtml()
{
    html=header;
    html+=body;
    html+="</html>";
    return html;
}
