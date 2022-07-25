#pragma once

// Время
#define convert_seconds_to_milliseconds(seconds)           (long) seconds      * (long) 1000
#define convert_milliseconds_to_microseconds(milliseconds) (long) milliseconds * (long) 1000

#define convert_seconds_to_microseconds(seconds) convert_milliseconds_to_microseconds(convert_seconds_to_milliseconds(seconds))

// Расстояние
#define convert_centimeters_to_millimeters(centimeters) (long) centimeters * (long) 10
#define convert_millimeters_to_microns(millimeters)     (long) millimeters * (long) 1000
#define convert_microns_to_nanometers(microns)          (long) microns     * (long) 1000

#define convert_millimeters_to_nanometers(millimeters) convert_microns_to_nanometers(convert_millimeters_to_microns(millimeters))
#define convert_centimeters_to_nanometers(centimeters) convert_millimeters_to_nanometers(convert_centimeters_to_millimeters(centimeters))
