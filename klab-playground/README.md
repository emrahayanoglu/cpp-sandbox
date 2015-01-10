# KLab/PlaygroundOSS

``` sh
# install AndroidNDK
curl -$ANDROID_NDK_ROOT:$PATHhttp://dl.google.com/android/ndk/android-ndk-r9-linux-x86_64.tar.bz2 > /tmp/android-ndk.tar.bz2
tar xvjf /tmp/android-ndk.tar.bz2 -C /usr/local/android-ndk
ANDROID_NDK_ROOT /usr/local/android-ndk
PATH $ANDROID_NDK_ROOT:$PATH
rm -rf /tmp/android-ndk.tar.bz2

# rebuild engine
git clone https://github.com/KLab/PlaygroundOSS.git
cd PlaygroundOSS/Engine/porting/Android/GameEngine-android
NDK_PROJECT_PATH=`pwd` ./build.py --rebuild --project SampleProject                                                                                                                                    
```

## References

- [KLab/PlaygroundOSS](https://github.com/KLab/PlaygroundOSS.git)
- [Android NDK | Android Developers](https://developer.android.com/tools/sdk/ndk/index.html)
- [2D/2.5Dゲームエンジン Playgroundのセットアップ - ブライテクノBlog](http://brightechno.com/blog/archives/150)
- [OSSのゲームエンジン「Playground」のハッカソンに行ってきたよ - hdk\_embeddedの日記](http://d.hatena.ne.jp/hdk_embedded/20131106/1383681073)
- [ahazem/android Repository | Docker Hub Registry](https://registry.hub.docker.com/u/ahazem/android/dockerfile/)

