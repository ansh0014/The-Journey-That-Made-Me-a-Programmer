// now i am doing the Angle Between Hands of clock
// first we have to understand the question 
// given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand
func angleClock(hour int, minutes int) float64 {
    hourAngle := float64(hour%12)*30 + float64(minutes)*0.5
    minuteAngle := float64(minutes) * 6

    angle := math.Abs(hourAngle - minuteAngle)

    if angle > 180 {
        angle = 360 - angle
    }

    return angle
}