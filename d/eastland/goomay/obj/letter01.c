
#include "../goomay.h"
inherit OBJECT;
void create()
{
set_name("paper","发黄的羊皮纸");
set_short("a paper","发黄的羊皮纸");
set_long(@PAPER
一张已经发黄的羊皮纸纸，上面写著密密麻麻的文字.\或\许\你可以试著去读(read)它.
PAPER
);
set("no_sale",1);
set( "unit", "卷");
set("weight", 5);
set("value", ({ 5, "silver" }));
}
void init()
{
add_action("read_letter","read");
}

int read_letter(string str)
{
    object ob1,room_1;
    if (!str ||str!="paper") return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write(
@C_MSG
哈哈哈 !!! 我终究还是逃出来了 ... 没想到这个地方会在最後关头助我最後
的一臂之力 ...

    我是精灵族魔法师－林特，在一次意外的魔法试验中，我和我的同伴 ( 也
就是现在追杀我的人 ) 魔族法师－普罗尼亚发现了合成人造生物的法术，这是
一项极其可怕的法术，我们很侥幸的利用精神控制制服了首次的成果－一只巨大
的火焰兽，我知道幸运女神不会常常眷顾著我们，运用这种违反自然的法术必将
遭受反噬，但是普罗尼亚已经著迷了，她竟然企图杀害我以夺取我的法力，因为
单凭一个法师的力量是绝对无法发挥那可怕咒语的威力的，我逃出来了，逃到一
个被神圣封印锁住的地方，可是我的生命也耗竭了。

    我并不在乎生或死，我只知道疯狂的普罗尼亚一定会想尽办法去取得强大的
法力来继续她的疯狂试验，甚至出卖灵魂也在所不惜，能来到这里的人啊 !! 你
一定不会是邪恶的一方，求求你一定要找到普罗尼亚，在她还没有毁灭世界之前
把她送入地狱 !! 愿神保佑你 !! 愿魔法之神永远与你同在 !!

				林特．坎恩 绝笔

C_MSG
              );
          return 1;      
        }
    }
}
