
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text("HEllo world")
        .fontColor(Color.Black)
        .width('100%')
        .height('20%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#F5F5F5')
  }
}