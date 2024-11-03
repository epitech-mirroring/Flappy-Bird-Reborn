if start then
    text.colorR = 255
    text.colorG = 0
    text.colorB = 0
end

--v1

--if text.colorR > 0 and text.colorG < 255 and text.colorB == 0 then
--    text.colorG = text.colorG + 3
--    text.colorR = text.colorR - 3
--end
--
--
--if text.colorG > 0 and text.colorB < 255 and text.colorR == 0 then
--    text.colorB = text.colorB + 3
--    text.colorG = text.colorG - 3
--end
--
--if text.colorB > 0 and text.colorR < 255 and text.colorG == 0 then
--    text.colorR = text.colorR + 3
--    text.colorB = text.colorB - 3
--end

--v2

if text.colorR == 255 and text.colorG < 255 and text.colorB == 0 then
    text.colorG = text.colorG + 3
end

if text.colorR > 0 and text.colorG == 255 and text.colorB == 0 then
    text.colorR = text.colorR - 3
end

if text.colorR == 0 and text.colorG == 255 and text.colorB < 255 then
    text.colorB = text.colorB + 3
end

if text.colorR == 0 and text.colorG > 0 and text.colorB == 255 then
    text.colorG = text.colorG - 3
end

if text.colorR < 255 and text.colorG == 0 and text.colorB == 255 then
    text.colorR = text.colorR + 3
end

if text.colorR == 255 and text.colorG == 0 and text.colorB > 0 then
    text.colorB = text.colorB - 3
end
