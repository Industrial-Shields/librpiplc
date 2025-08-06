# Changelog

All notable changes to this project will be documented in this file.

## [4.1.0] - 2025-08-05

### 🚀 Features

- ABI automatic checking ([8a49ca3](8a49ca394433436d67e23c937740b35a9256e81a))

- Add basic Raspberry Pi model detection ([12be3f3](12be3f36c590aba15dbf2e36403efeb1970e9d63))


### 🐛 Bug Fixes

- Add QX mapping that matches TouchBerry serigraphy ([4444da1](4444da1db05522bafb0b2f60c26075ba947b3150))


### ⚙️ Miscellaneous Tasks

- Remove Bump library version and Update ABI Dumps from changelog ([02b130c](02b130cb3d2b948b4d328c344b505456ef6b4eb4))


## [4.0.0] - 2025-07-03

### 🚀 Features

- [**breaking**] Merge branch 'new-pins-enum' and update plc-peripherals ([7a140b9](7a140b9a0e96c9701488d97689704c9c6ec3b079))

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

- Fix debug release in CMakeLists ([cc3bc56](cc3bc564de30a9d34f139d3c2bbb6724b7e57b6c))

- Fix analogBlinkAll example ([bb83db4](bb83db4b5593957f8b9141148f6cc5ef1a53ae64))

- Fix gpio_fd bad conditional + Remove compilation errors ([6587add](6587add0aa4246db0fbc89b329bc6eba055e11b0))


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

- Initial .deb package ([54c4f73](54c4f73ee12104ce774e5a448e531fb90b7ceff1))

- Add getVersion test ([5034c18](5034c187356ad9ac3f7848e2aba51b1a7a999969))

- Add support for GateBerry V9 ([3bb9ed1](3bb9ed12d509f327f2b861098dbd4396a825f4bd))

- Remove CS0 and CS1 from the Touchberry examples

They will most likely conflict with the Raspberry Pi's SPI overlays. ([6097fe3](6097fe35a343cc14c0ba1ecf5d1df52bd67260e8))

- Touchberry V1 basic mappings (missing expansor pins) ([fe19919](fe1991905c1861db487a54525e0142942291f6b6))

- Enable return of positive values in normal GPIOs init and deinit functions ([3bf7a69](3bf7a697c1ff3dd472984eaf9eb68df51091baf2))

- Add comment to lib/CMakeLists.txt ([2e45615](2e45615ab24c62b8a5ce1a5d6a13ac404de61472))

- Add -Wextra in librpiplc compilation ([f902996](f902996d0a3577a358ddfdf90ab16e94954e8879))

- Make the library compatible with UPSafePi V6 ([04d8889](04d88890cd23f9e3377d4944e5bcc0d1348f6ed1))

- Update lib/CMakeLists ([99136a3](99136a3b2a90c26d9cc9546f3d5b5e5c0a923123))

- Add LTC exceptions for RPi PLC 21 and 19R ([c73afba](c73afbab6f3a75fa98e37cca225829e69ab733a7))

- Give more information when some error is detected in test programs ([3374f6a](3374f6a10eaf997547957dc812076744c3ad4b2a))

- Rebase from origin + Adapt to last plc-peripherals ([5984e89](5984e89ea839b1fb6b61d36ffcde67fc68eca210))

- Update rpiplc mappings ([ad31531](ad31531a96b2649497fe0eee58af61b2a3fa1419))

- Revert "Bump plc-peripherals + Simplify include directives for the library"

This reverts commit 3a2da9f5e816fede0a8086d10e49127ec5558dea. ([b138610](b138610b9214faca29acaf42295d55f855cc2453))

- Enable compile-time I2C bus and peripherals selection + Initial UPSafePi V6 support
It requires to compile all your project along with a .c file that defines these variables depending on the macros you selected ([68c5792](68c57921c0dbfb8c17aa0a22a2463652019080b6))

- Bump plc-peripherals + Simplify include directives for the library ([3a2da9f](3a2da9f5e816fede0a8086d10e49127ec5558dea))


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

- Use pinMode in tests programs, instead of relying in hw-config ([13b69e4](13b69e44665ac4db9641cc5595a4c17dbb91e4a4))


## [3.0.1] - 2024-05-20

### 🐛 Bug Fixes

- Fix compilation for only one version and model to build tests for ([07f509e](07f509eb671bdafb45e0b360548eacf40e7e2d3c))


### 💼 Other

- Revert "Support for UPSafePi V6 + Update plc-peripherals to v1.0.1"

This reverts from commit 07f509eb671bdafb45e0b360548eacf40e7e2d3c to commit 0cd8da232476fdd1b16a8065a4a81024f58d2ccb. ([d156cb8](d156cb8cf7ded1d1f5be753aa5823eabb7849be5))

- Update README to reflect availability of UPSafePi ([67587df](67587df41a3ebe2bd96149cb6df213196868ba80))

- Support for UPSafePi V6 + Update plc-peripherals to v1.0.1 ([0cd8da2](0cd8da232476fdd1b16a8065a4a81024f58d2ccb))

- Add INT31 pin for Raspberry PLC V6 ([a18aa55](a18aa55ccfdd4f857785d8c0d7ae11780e04addd))

- Remove PWM pins (they are not present in V6) ([be58a47](be58a47ca60be380b146896576f7bd44fee5a5a4))

- Update README ([1579952](15799528083cb2c80f7d1896e292d198cbf0d819))


## [3.0.0] - 2024-04-25

### 🐛 Bug Fixes

- Fix include directives for G++ in README ([2a3c3d8](2a3c3d87d6bc71e57903bd4fcfb44e840363d6c1))

- Fix Debug flags ([eaf9d36](eaf9d367c624614ab77a40aa5dc5472d8eed9403))

- Fix README + Pass CMAKE_BUILD_TYPE to plc-peripherals + Close GPIO if pinMode is used for a used GPIO ([e50db73](e50db7393880638b4ae7750da528328073a83532))

- Fix #error messages from pins_references-vX.hpp ([22405cd](22405cd456989828513ff20b7d7314b57beb097b))

- Fix OPTO_OUT_2 PLC V5 mapping ([f4388e4](f4388e450ba0db23456eb32f4de1ed447acf0df7))

- Fix naming of EXP2 RST line ([ad6ab23](ad6ab23ea3bbcbba5a787366052b2eacb245dcd0))

- Fix CMake indentation + Remove echo from prepare_cmake.sh ([756013b](756013b2b225654a4067b53960bf11b3434217e3))


### 💼 Other

- Update README + Fix assert in Arduino functions ([48e95c8](48e95c80e6a4fc32d73b42595ee37deefe930fee))

- Add sudo ldconfig in README ([1cdd3ac](1cdd3acca20c4afdf12b53f799b7814b28b99d50))

- Use v1.0.0 tag for plc-peripherals ([dd39a06](dd39a0641b764ba0b6a389bfbe4560d1e8cb9849))

- Update .gitignore ([497450e](497450ee5b100d3ffd7e8f6e5d27c2760e7b1893))

- Change name of RPIPLC V5 to RPIPLC V6 to avoid future confusion ([94a991c](94a991c98284c5cf8b464d7a64aac78d171810c4))

- Pass -fPIC to plc-peripherals + Fix analogBlink test compiling to RPIPLC ([910a487](910a48732c4f274f1a9807666c21011166093d5e))

- Extract version macros to the header ([19f417f](19f417f677ba3be3ad7407b71848f44361b56f1b))

- Better version header and print version in tests + Fix tests not initialising with new hw-config ([9860eca](9860ecaa35e2fb7db951f2109c601528d9bf803a))

- License the library under the LGPL-3.0-or-later and the tests under the GPL-3.0-or-later ([31a89d5](31a89d5f0fa0e1a4ab05f6beed8fc4747d09de39))

- Documentation + Bump version in the header ([1597d10](1597d1040b15ea05015d723b8539961762fa0f65))

- Differentiate PWM and I/O pins + Create FDs if don't exist + Better tests ([8a4aa45](8a4aa45ea3274ffc432da3e7c0a01e9aae70d9cf))

- Add new plc-peripherals PWM functions + Add more pins as possible PWM outputs ([5522028](552202884c4e78248ff176b60b71bab08bc84d0d))

- Optionally change the PWM frequency whe using set-pwm-output ([dab05fa](dab05fa231617686ae4ed0fb4da96d01b4d9d4dc))

- Make an extra folder for relative #includes ([1c40649](1c406490185ee6c3083760e1a3a1b55147f4abf9))

- Add EXP as digitalOutputs + Correct README ([224a7a6](224a7a6c5da314a8e57a5e5379f349f3968fa375))

- Install library headers (forgot to uncomment) ([8193aef](8193aefc1a7ba8e3126d4e7d760d1e265d7b4a23))

- Better test suite + Update README + Add "RPIPLC" as model ([21f13f4](21f13f43809095cde923face8f25984ad81783db))

- Ensure that analogBlinkAll only blinks analogic outputs (not relays) ([1a942ec](1a942ec3fc8ff110815ce262eb4473b62dc88842))

- Debug and Release build types + Fetch plc-peripherals directly with CMake, wihout Git submodules ([6772532](6772532f1cba806842cee83a9919d41fc214cfe8))

- Use CMake commands instead of custom build script + Bump plc-peripherals ([5595ff0](5595ff00f9a2f02efaa5cfd259e51e5c5fe785b1))

- Update rpi-gpio to use GPIO_V2 Linux API + Better error handling ([70f86d7](70f86d735e86a1b7fe71e55e0b8702c8c0cbcc3c))

- Add MCP23017 empty array and other functions + Better delays ([f80af61](f80af61df79ae94205decf00448d43b7f7d235a3))

- Rename "test" directory to "tests" + Fix initExpandedGPIO callings ([7974029](7974029f3e018d3d8fac8dc52ea65fd7fdcf0151))

- Bump to last plc-peripherals lib ([831d365](831d36523ca9b3914907f8a70bab727c1903ccd0))

- Import PLCs peripherals as a library + Fix tests warnings ([eee6cfe](eee6cfe38be76dedf05c5f9259bf378f0b61e890))

- Change underscores to hyphens to maintain coherence with other .hpp ([5b384ee](5b384ee25b00c573edbf1cc310883df2c024e896))

- Rename library to librpiplc ([67a6bfc](67a6bfc72592e5398fab5512d8877e84c0623b14))

- Downgrade CMake and C/C++ standards to match Debian Bullseye + Fix size_t prints ([5c166d5](5c166d573ec11a6b0a0787ab8fe261200743b1c4))

- Macro to not include rpiplc-mapping.h (useful for libraries) ([abb9803](abb980324e7ff2a22d9ad12b768a4262850e8bec))

- Only build tests if version and model macros are given ([d7c1786](d7c1786065d90adcdeda90e87299be151430c494))

- Change nullptr in the library to NULL ([394e50e](394e50e79faa684455da73966eb358645225e8f8))

- Compile library with C and make it compatible with C++ + Change optimization levels and standards used ([624a5ab](624a5aba3c01e364a3a540ea9fca2a1e4af5b1f8))

- Add RPi PLC V5 mapping + Make some corrections in v4 pins_references to test ([1115c5e](1115c5ece41c129aa410cafd5a675e0f1136f6f3))

- Enable all warnings as errors + Enable multithreaded compilation + Remove unused code in shellscripts ([0fd1fe3](0fd1fe36620648271ebde46c191b1efcc4da0027))

- General test refactoring + Start updating the README ([27875f2](27875f22573a4dc92fc34210ca6656dc2428cc83))

- Move install.sh to only build.sh, and enable installation through arguments ([068e7ee](068e7ee15f67e33298a64551b549465af8475c59))

- When installing, also install test files ([a39dd17](a39dd17087e59d302b9acbab8695bcca62e73c4e))

- Make tests version agnostic ([ae9dc0b](ae9dc0b338bdf91917434dbc05d48553cf0e5271))

- Remove duplicated code + Fix 57ARA name ([df0337c](df0337cbb3d1b8e8a203b0f0a82cd64fca27c80f))

- Add missing pins in v3 pin mapping ([3fa0a05](3fa0a05bbdfd072770df50878778b07107f8ca74))

- Enable compilation of all versions and models at the same time ([1768f77](1768f77281709183ec34aa67b4f4e1e42144c247))

- Use macros to select which PLC version to compile for ([90c08fb](90c08fb9485f61948bd78845359c7a5504382f03))

- Use CMake + Change some installation locations ([1dc23bd](1dc23bd3a76294b45b4f6cc6b63c831c039966c7))


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
