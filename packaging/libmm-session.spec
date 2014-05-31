Name:       libmm-session
Summary:    mm-session development pkg for samsung
%if 0%{?tizen_profile_mobile}
Version:    0.2.7
Release:    1
%else
Version:    0.4.4
Release:    0
VCS:        framework/multimedia/libmm-session#libmm-session_0.3.0-1-22-g6a3c3f7b59fa541df2bdad411b5b2a6761fd808f
%endif
Group:      System/Libraries
License:    Apache License, Version 2.0
URL:        http://source.tizen.org
Source0:    libmm-session-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(audio-session-mgr)
BuildRequires:  pkgconfig(mm-common)


%description
mm-session development package for samsung



%package devel
Summary:    mm-session development pkg for samsung (devel)
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
mm-session development package for samsung (devel)


%prep
%setup -q


%build

%if 0%{?tizen_profile_mobile}
cd mobile
%autogen
CFLAGS="$CFLAGS -Wp,-D_FORTIFY_SOURCE=0"
%configure
make %{?_smp_mflags} 
%else
cd wearable
./autogen.sh
CFLAGS="$CFLAGS -Wp,-D_FORTIFY_SOURCE=0"
./configure --prefix=/usr 
make %{?jobs:-j%jobs}
%endif

%install
rm -rf %{buildroot}

%if 0%{?tizen_profile_mobile}
cd mobile
%else
cd wearable
%endif

mkdir -p %{buildroot}/usr/share/license
cp LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}
%make_install


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%if 0%{?tizen_profile_mobile}
%manifest mobile/libmm-session.manifest
%else
%manifest wearable/libmm-session.manifest
%endif
%defattr(-,root,root,-)
%{_libdir}/libmmfsession.so.*
%{_datadir}/license/%{name}

%files devel
%defattr(-,root,root,-)
%{_includedir}/mmf/*.h
%{_libdir}/libmmfsession.so
%{_libdir}/pkgconfig/mm-session.pc
