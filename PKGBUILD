# Maintainer: Thule <vincenzo.frascino@proton.me>
# Contributor: Neptune <neptune650@proton.me>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm_custom
pkgver=6.6.21
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="https://github.com/Kisbogyi/dwm"
arch=('i686' 'x86_64' 'arm' 'armv7h' 'armv6h' 'aarch64')
license=('MIT')
options=(zipman)
provides=('dwm')
depends=('libx11' 'libxinerama' 'libxft' 'freetype2')
# install=dwm.install
source=(git+https://github.com/Kisbogyi/dwm)
sha256sums=('SKIP')

prepare() {
	# Its mine so no preparation needed
	:
}

build() {
  cd "$srcdir/dwm"
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 FREETYPEINC=/usr/include/freetype2
}

package() {
  cd "$srcdir/dwm"
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
