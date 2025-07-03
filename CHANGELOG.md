# Changelog

All notable changes to this project will be documented in this file.

## [4.0.0] - 2025-07-03

### 🚀 Features

- [**breaking**] Merge branch 'new-pins-enum' and update plc-peripherals ([68879b7](68879b71c1e843db92d9bf3aa30f03568a3bd0e0))

- Remove initExpandedGPIO breaking change ([ce918fe](ce918fe48a20453ea804b57956717f8883200380))

- Change RPIPLC macro to RPIPLC_CPU ([98aa2a8](98aa2a8a1e73cbf1ddabb6bac77d74a95426b0c4))

- Add GateBerry V9 click mapping ([596a7b9](596a7b9e1a0210b8ea0f45f4238a5ed0bd723f3f))


### 🐛 Bug Fixes

- Append debug flags in CMake ([e459eda](e459eda9d67724f10bcd0151b94b79a32fe481bd))

- Reduce Debian dependencies, and make the package truly multi-arch ([cd4d287](cd4d28720a2b056118c1daad420b153c50de6999))

- Silence read-in-maintainer-script lintian error ([9427fac](9427fac585df52b60046914f7915a94b864a9c1c))

- Install headers inside librpiplc/ directory ([29409f2](29409f2ed06e58d5f9df490579c2bc88b9b87188))

- Ask to proceed with the APT installation ([f70af8e](f70af8e6064304e4d9d17dde3243bde029cab31f))

- Update clean_debian target ([ed57dba](ed57dba6b08cd83a676b35482b4a92c3a5f3d177))

- ~/test/ symlink creation when installing librpiplc ([5cccfc0](5cccfc0972fddb103829d752fb33bafa88dfbe08))

- Fix RPIPLC_V4 and RPIPLC_V3 test compilations ([0244a51](0244a51a82f6f944aa7ef73103e7b949ab193956))


### 💼 Other

- Update debian/changelog ([64fb869](64fb86926fb1bbbcc591953040463c372a2e20e1))

- Update clean_debian target ([be7fc2f](be7fc2f04203e46f8ad437f526e1f1fbcf9f0c45))

- Compile all tests when creating .deb package ([38b7bcc](38b7bccafd0bc7c20fbeec3962ebb805ec2ca70d))

- Add support to cross-compile from armhf to arm64 in .deb package ([a9b3a15](a9b3a1572c4feafe17c980791c2be754c14f5e4b))

- Add sign key to .deb packages + Fix mv command ([382389c](382389cfb2956b0ea8699137afc3d9a5951e7be8))

- Modify debs target in Makefile ([d446d1c](d446d1c678759575fd1434f8581fb9c0864c041f))

- Add optional priority to test packages ([20854e1](20854e12f1ef7f0d3985578db8cee21e384fcb17))

- Test packages for GATEBERRY_V9, TOUCHBERRY_PI_V1 and UPSAFEPI_V6 ([ccff204](ccff204f4cefef48a35d90c987dff6d1d3e9babc))

- Update VERSION and SOVERSION inside CMake ([201b89f](201b89f1d7a0f17989fe662d1c0ca25ef71227a7))


### 📚 Documentation

- Update README with apt package, build instructions and general fixes ([6e50fe0](6e50fe03ecc3c14a4efba9da407e19fd4dccfdda))


### ⚙️ Miscellaneous Tasks

- Update clean_debian ([c84ee1a](c84ee1abf79b4b2f66ebf81afb1ab586d7b34225))

- Update bug fixes cliff regex ([19205eb](19205ebf57ba06519613d0cb8eb9ee8bb7546731))

- Update Debian changelog ([3c7e618](3c7e618b9deb1e39db126beabd58e972a03a2dbb))

- Add CHANGELOG file ([74ae5ae](74ae5ae7a055dc4ff38b7741a7e86e3bc7bdf291))


## [3.0.2-hf] - 2024-05-27

### 💼 Other

- Remove PIN8 from tests
By default our images enable the SPI0-2CS overlay, and the tests will fail when trying to test this pin (as it's the CS of SPI0). This commit fixes this problem ([5151468](5151468039ccb40f792d0e755a3c4ffc4b46eb6e))


## [3.0.2] - 2024-05-27

### 💼 Other

- Bump library version ([c3a0c4e](c3a0c4e6ac154d4b42b9ff27c50d17738fa19c9e))

- Use pinMode in tests programs, instead of relying in hw-config ([13b69e4](13b69e44665ac4db9641cc5595a4c17dbb91e4a4))


## [3.0.1] - 2024-05-20

### 🐛 Bug Fixes

- Fix compilation for only one version and model to build tests for ([07f509e](07f509eb671bdafb45e0b360548eacf40e7e2d3c))


### 💼 Other

- Plc-peripherals v1.0.1 + Bump library version ([3be0593](3be0593a2bb0f7199c3eb0aead5d1a8142f71ede))

- Revert "Support for UPSafePi V6 + Update plc-peripherals to v1.0.1"

This reverts from commit 07f509eb671bdafb45e0b360548eacf40e7e2d3c to commit 0cd8da232476fdd1b16a8065a4a81024f58d2ccb. ([d156cb8](d156cb8cf7ded1d1f5be753aa5823eabb7849be5))

- Update README to reflect availability of UPSafePi ([67587df](67587df41a3ebe2bd96149cb6df213196868ba80))

- Support for UPSafePi V6 + Update plc-peripherals to v1.0.1 ([0cd8da2](0cd8da232476fdd1b16a8065a4a81024f58d2ccb))

- Add INT31 pin for Raspberry PLC V6 ([a18aa55](a18aa55ccfdd4f857785d8c0d7ae11780e04addd))

- Remove PWM pins (they are not present in V6) ([be58a47](be58a47ca60be380b146896576f7bd44fee5a5a4))

- Update README ([1579952](15799528083cb2c80f7d1896e292d198cbf0d819))


## [3.0.0] - 2024-04-25

### 💼 Other

- Update README + Fix assert in Arduino functions ([48e95c8](48e95c80e6a4fc32d73b42595ee37deefe930fee))

- Add sudo ldconfig in README ([1cdd3ac](1cdd3acca20c4afdf12b53f799b7814b28b99d50))

- Use v1.0.0 tag for plc-peripherals ([dd39a06](dd39a0641b764ba0b6a389bfbe4560d1e8cb9849))


## [2.0.1] - 2023-08-21

### 💼 Other

- DigitalRead compatibility with Raspberry PLC v4 ([5b7e158](5b7e158574c58600705ada7aeca724135fdfc386))

- Update README.md ([94b8b69](94b8b6934c9c27fd9179e198e7c840420f513f58))

- Update README.md

add available rpiplc models ([c5cf634](c5cf6343f8f3f3c34c8ec03f48ac12f33f613d89))

- Update common.h ([d946386](d946386fa17b92161d7771b8707f62b102c02dc3))

- Update pins_reference.h

Add exp1_rst_2 ([66a874e](66a874e6c2b7863cf6e4651f949c2b56f12951f7))

- Update rpiplc-mapping.h

Add exp1_rst_2: 0x0000400A ([1436d51](1436d5126ee9ad6280fce00d7fa2335bfceef754))

- Update README.md ([5a7d735](5a7d735e514938fc45e04af320cfee6fed8b9902))

- Update README.md ([4ac3223](4ac3223112a9ce1206d1c692e5389f435c432b3c))

- Update README.md

Tagname option when cloning the repository for v2.0.0 (RPI PLC v4) added. ([c7a8344](c7a8344ad7a64df3df5091a919b1b574f274938f))


## [2.0.0] - 2022-06-30

### 🐛 Bug Fixes

- Bug fix: delete duplicated code rpiplc ([896fbd1](896fbd1cf7eb9c79d81a317794b509e32511b9b2))

- Bug fix: i2c write mcp23008 ([e52f77f](e52f77fb23c35be409a038fddb393ec1b7276546))

- Bug fix: check pca9585 status before init ([f4a8b99](f4a8b994c505189055b0dc52a8ba5382c1841715))

- Bug fix

Delete error in typing ([5c4d5f5](5c4d5f563b8a95b860bdee9693ee0ec5c6830596))

- Bug fix

Add I0.0, I0.1, I1.0, I1.1, I2.0, I2.1 ([5ae9909](5ae990932f8894ac905aa3ddeca53dc3d45e0f56))


### 💼 Other

- Update README.md

The file README.md has been updated with the explanation of the PWM outputs usage. ([40e234f](40e234f74087f3f8b94000f99e318d18ff32fca5))

- Update PWM pins_reference.h

The file pins_reference.h has been updated with the addition of the PWM usage for all the digital outputs. ([69f00fa](69f00fa1e9ee18e9b60eaf090e6071d2bbf223bc))

- Update README.md

Add set-digital-output, set-analog-output, get-digital-input, get-analog-input ([aae2c77](aae2c770ab85ea284529d45068911c10be888652))

- Remove empty compile.sh ([15896cc](15896cc33ce5f394b9776c0613c65a1054314314))

- Modify rpiplc-mapping ([14884c6](14884c6aa79065e2a4172f251e127fa3a71d30db))

- Add pwms and pin8 in pins_reference file ([bfc08f7](bfc08f74f63a763b51182e1fad186e0944085ebd))

- First commit ([5f1b14b](5f1b14bc57ec2cf528f1c279e4ffa0a8d9eb80fb))

- Prevent MODE1 and MODE2 uncontrolled overwrite ([1ffae2f](1ffae2f82e36fe77c1d720874050d2b6a5fd3a08))

- Update README

Add digitalBlinkAll and analogBlinkAll ([a5be167](a5be167b40d09e2864db99db609e3bc97ca23b9a))


## [1.1.1] - 2022-01-04

### 🐛 Bug Fixes

- Bug fix

Delete "Note:" from line 35 ([5e30f42](5e30f42f7ce8640241f87d429e6aa43e7f203d50))


### 💼 Other

- Version 1.1.1 ([a3a934b](a3a934bf2077c172ea8ca28f69851a0e24c0d997))

- Add multiple digitalWrite and AnalogWrite at the same time ([c98a439](c98a439b74496209a1375b1d8ec06ecee4fa1ddd))

- Update README.md ([a7a32a1](a7a32a1e686b9d954d6bc49323e55ae4961fce74))

- Update README.md

Add Installing Git section ([26551c0](26551c0a0bd4ba199dff888a3c15423b3ec667b9))

- Update common.h ([c745867](c745867fd72fb41b2c4d569dc337e4f02898e54d))

- Update README.md

Add -L /usr/local/lib ([9ebc36c](9ebc36ce80a083334c6341914b86bb9b055349f2))

- Add Main 

Add main function to reference and explanation ([fc117fb](fc117fb47e7b1c40274ff1705102867522bc6c50))


## [1.1.0] - 2021-07-01

### 🐛 Bug Fixes

- BUG FIX: ads1015 buffer overflow ([7045b97](7045b97520bb92bbf718c8760b2dff7e461738bc))


### 💼 Other

- Version 1.1.0 ([fb9636c](fb9636cb96f1d1c52e685ae07a2585e471671273))

- Remove main from library ([9712858](9712858655bc1eb682ae321f112944342f19e3fa))

- Update README.md

Bug fix: Add a line in Installing > 6. ([d73cf8a](d73cf8acf466ff2a3214042e4cbfd179fc063503))

- Update README.md

Bug fix: set h2 to reference ([522bff1](522bff188687808ea428cce1f7051c067c1ad41a))

- Update README.md

Bug fix README ([1b13807](1b13807d0d5481be781908d669add41740f256f9))

- Update README.md

Add the README.md to the GitHub ([c8020de](c8020ded96ee0c96473d364cd4f3ef1aa14d9989))


## [1.0.2] - 2021-05-20

### 🐛 Bug Fixes

- BUG FIX: define I2_5 and I2_6 ([224ef35](224ef35433adb0edaadbc158a99dfc440e9fd5d9))

- BUG FIX: pack target ([98e1a58](98e1a58bcffbe06dbf70cfd9c50d3ebcb7b4248d))


### 💼 Other

- Set version 1.0.2 ([4878f27](4878f272c02ab29a65cc0ab4827f17eff4c1b30e))

- Use LIBNAME to pack ([7cd599d](7cd599d269c9de0ef699430e4856077414d58f51))

- Add pack target ([d83648d](d83648d0b211e35f4c3bcbe52f75bdb1635b27f6))


## [1.0.1] - 2021-05-17

### 🐛 Bug Fixes

- BUG FIX: MCP23008 init ([20b42a4](20b42a47565d4ad3f4a887a9530f6c897ad0b31e))

- BUG FIX: print size_t ([f5bf9a5](f5bf9a5dea92fb87330232530502fa938d01804c))

- BUG FIX: remap pins ([8a2d5b4](8a2d5b419aa2e2545bab5f48f3c6bbe9274e13f5))


### 💼 Other

- Add version file ([fe09f32](fe09f32737dc6eeac24d41a0787cb007c70ed5d9))

- Add direct digital inputs ([b3db22f](b3db22f835113553450bea95f7557446ff96ba37))

- Add direct RPI pins ([546a71a](546a71a23997e09ae64b0d78f54726fe4933bf76))

- - Add RPIPLC modules
- Reimplement using C++ ([6f3d33d](6f3d33d325c224c8b2f989a84c65eaa52c150590))

- Add digitalRead and digitalWrite functions ([fc51bd0](fc51bd0b3c12bd55183703f1b579a7e1828102b0))

- Add analogRead method ([550bffa](550bffa06acc1f0ab407d2c07097729b87465d71))

- Add value argument to analogWrite test ([17df6ef](17df6efdf238bac84c6b8b0dcb662b1809cfdcf2))

- Add analogBlink test ([6ebb9ac](6ebb9ac8bf453d55ae06a34d83e8161f9048b987))

- Build depends on headers ([c51764c](c51764cd175d11195ab121b46a4483e14e214a79))

- Notify errors ([6d65f11](6d65f11796f31062242ead1e5e9e92d85876c462))

- Create README.md ([8ef4656](8ef46566fe23da58de52b80c10315c6ea026e330))

- Tests depend on library on Makefile ([2e05c5b](2e05c5b08d89141f949aabbcfb220c0b44c412ca))

- Remap pins ([e6e6cdc](e6e6cdc1cc02ab336c3035e5b7223d9bad4213f3))

- Add DESTDIR into Makefile ([4689f33](4689f33b87f584f1a1a26f02069b0a9bd59ee3d9))

- Define I2C bus ([b3d1000](b3d100090b60b900324257d9bc5a852c6608fc12))

- First commit ([c4d47a9](c4d47a99cc675e31b47f9594d423688acfea106b))


<!-- generated by git-cliff -->
