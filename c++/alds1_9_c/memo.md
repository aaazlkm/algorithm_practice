# alds1_9_c

- delete について思いを馳せる
  - child がいない場合は、iを削除
    - childが片方がいる場合は、入れ替え
    - さらに下の要素のことを考えないといけない
    - 一個ずつ上にずらさないといけないの普通にしんどいな
    - nodeでやらないと無理じゃね...??
    - でも回答だと、max heapでやってるわ....どうやるんだ？？
    - 一個ずつ移動するパターンは無理な気がする
      - 書いて考えてみたが、child -> parentに遷移する計算が、深さによって異なる
      - ここの計算ができる気がしないし、できたとしてもうまくない感じがする
    - 残りのものを再度insertするパターンは？
      - アリかもしれない、そっちの方が早そう毎回lognの計算がかかってしまうけど...
  - ~~childが両方がいる場合は、ちょっと考えないといけない~~ -> 
    - このパターンはない、一番右の要素に移動してるはずだから