@echo off

IF EXIST vcpkg (
	set _TMP=
	for /f "delims=" %%a in ('dir /b "vcpkg"') do set _TMP="%%a"
	IF NOT {%_TMP%}=={} (
		rmdir vcpkg
		curl -LJO https://github.com/microsoft/vcpkg/archive/master.zip
		tar -xf vcpkg-master.zip
		del vcpkg-master.zip
		rename vcpkg-master vcpkg
	)
) ELSE (
	curl -LJO https://github.com/microsoft/vcpkg/archive/master.zip
	tar -xf vcpkg-master.zip
	del vcpkg-master.zip
	rename vcpkg-master vcpkg
)

.\vcpkg\bootstrap-vcpkg.bat

IF "%PROCESSOR_ARCHITECTURE%"=="AMD64" (
	.\vcpkg\vcpkg.exe install sdl2 sdl2-image sdl2-mixer sdl2-ttf box2d enet --triplet x64-windows
) ELSE (
	.\vcpkg\vcpkg.exe install sdl2 sdl2-image sdl2-mixer sdl2-ttf box2d enet --triplet x86-windows
)

PAUSE
