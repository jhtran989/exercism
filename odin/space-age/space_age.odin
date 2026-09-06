#+feature dynamic-literals

package space_age

Planet :: enum {
    Mercury,
    Venus,
    Earth,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune,
}

PLANET_ORBITAL_PERIOD_IN_EARTH_YEARS_MAP := map[Planet]f64 {
    .Mercury = 0.2408467,
    .Venus   = 0.61519726,
    .Earth   = 1.0,
    .Mars    = 1.8808158,
    .Jupiter = 11.862615,
    .Saturn  = 29.447498,
    .Uranus  = 84.016846,
    .Neptune = 164.79132,
}

// Error with typed constants (expected an operand)
//EARTH_YEAR_SECONDS: int :: 31557600
SECONDS_PER_EARTH_YEAR :: 31557600

age :: proc(planet: Planet, seconds: int) -> f64 {
    earthYears: f64 = cast(f64)seconds / SECONDS_PER_EARTH_YEAR
    planetYears: f64 =
        earthYears / PLANET_ORBITAL_PERIOD_IN_EARTH_YEARS_MAP[planet]

    return planetYears
}
