#include "pch.h"

const char * headerText = "<?xml version=\"1.0\"?>\n<ArrayOfEntity xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">\n";

const char * cellText = 
    "  <Entity>\n" \
    "    <Label>%s</Label>\n" \
    "    <LambdaWidth>0</LambdaWidth>\n" \
    "    <LambdaHeight>0</LambdaHeight>\n" \
    "    <LambdaX>0</LambdaX>\n" \
    "    <LambdaY>0</LambdaY>\n" \
    "    <LambdaEndX>0</LambdaEndX>\n" \
    "    <LambdaEndY>0</LambdaEndY>\n" \
    "    <Type>Region</Type>\n" \
    "    <ColorOverride>%s</ColorOverride>\n" \
    "    <LabelAlignment>GlobalSettings</LabelAlignment>\n" \
    "    <Priority>0</Priority>\n" \
    "    <PathPoints>\n" \
    "      <PointF>\n" \
    "        <X>%d</X>\n" \
    "        <Y>%d</Y>\n" \
    "      </PointF>\n" \
    "      <PointF>\n" \
    "        <X>%d</X>\n" \
    "        <Y>%d</Y>\n" \
    "      </PointF>\n" \
    "      <PointF>\n" \
    "        <X>%d</X>\n" \
    "        <Y>%d</Y>\n" \
    "      </PointF>\n" \
    "      <PointF>\n" \
    "        <X>%d</X>\n" \
    "        <Y>%d</Y>\n" \
    "      </PointF>\n" \
    "    </PathPoints>\n" \
    "    <WidthOverride>0</WidthOverride>\n" \
    "    <Children />\n" \
    "    <Visible>true</Visible>\n" \
    "    <WireLengthLambda>0</WireLengthLambda>\n" \
    "    <WireTangent>NaN</WireTangent>\n" \
    "  </Entity>\n";

const char* footerText = "</ArrayOfEntity>";
