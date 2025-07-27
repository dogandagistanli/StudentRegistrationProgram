package com.example.demo;

import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api")
public class DemoController {

    @GetMapping("/hello")
    public String hello() {
        return "Merhaba API!";
    }

    @PostMapping("/echo")
    public String echo(@RequestBody String body) {
        return "Gelen: " + body;
    }
}
