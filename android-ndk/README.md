# AndroidNDK

``` sh
# install AndroidNDK
curl -$ANDROID_NDK_ROOT:$PATHhttp://dl.google.com/android/ndk/android-ndk-r9-linux-x86_64.tar.bz2 > /tmp/android-ndk.tar.bz2
tar xvjf /tmp/android-ndk.tar.bz2 -C /usr/local/android-ndk
ANDROID_NDK_ROOT /usr/local/android-ndk
PATH $ANDROID_NDK_ROOT:$PATH
rm -rf /tmp/android-ndk.tar.bz2
```

## References

- [Android NDK | Android Developers](https://developer.android.com/tools/sdk/ndk/index.html)

