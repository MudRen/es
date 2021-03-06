#include <../mumar.h>
inherit "/d/eastland/mumar/mumar_army";
 
void create()
{
        object ob1;
 
        ::create();
        set_level(5);
        set_name( "old soldier", "老兵" );
        add( "id", ({ "soldier" }) );
        set_short( "老兵" );
        set_long(
  "你看到一个满身是疤的老兵，正坐在一个帐蓬旁整理东西，以他对牧马关的了解，\n"
  "你有问题或想打听谁的事，问他是错不了的。\n"
        );
        set( "gender", "male" );
        set( "alignment", 200 );
        set( "wealth/silver", 50 );
        set( "natural_armor_class", 25 );
        set( "natural_defense_bonus", 10 );
        set_natural_weapon( 2, 1, 1 );
        set_perm_stat( "str", 5 );
        set_perm_stat( "dex", 7 );
        set_skill( "dodge", 50 );
 
        ob1 = new( OBJS"dagger1" );
        ob1->move(this_object());
        wield_weapon(ob1);
        set( "inquiry", ([
 "soldier" : ({ "嗯...俺听说有个小兵偷了武器库里的东西跑了，俺是不清楚他偷了啥\n"
                "玩意啦，不过军师最近几天都在库房里清点东西，好像很紧张的样子。\n" }),
 "rat" : ({ "嗯...说到老鼠...俺那天看到一只大老鼠背著一袋米跑出伙房，那畜生\n"
            "一看到我就跑回伙房去了，可是我和伙夫们找了好久就是找不到。如果我再遇到，\n"
            "我非好好教训教训它不可。\n" }),
 "lee" : ({ "李将军是我们的大家长啊...虽然听说他是靠他老婆才爬到这个地位，\n"
            "但是他功\夫还真不错。我当那麽久的兵，还是第一次看到有这麽强的节度使。\n"
            "不过，我也是第一次看到这麽爱收集古董的年轻人。\n"}),
 "master" : ({ "嗯...那个教头啊....实在有够臭屁的...不想提他...\n"}),
 "advisor" : ({ "嗯...这个军师啊...最近好像在为一个逃兵(soldier)而忙著呢!!\n" }),
 "guard" : ({ "嗯...守卫都是很尽忠职守的...只有像我这样的够老的兵才能担任喔..\n" }),
 "groom" : ({ "嗯...那个马夫啊..最讨厌有人骑马跑进马房，不过如果你有令牌(mark)的话，\n"
              "他应该也会让你几分。\n" }),
 "mark" : ({ "嗯...令牌啊...我只知道那个金光闪闪的东西在将军身上。\n" }),
 "hen" : ({ "嗯...哼将军是个刚正不阿的家伙，整个人冷冰冰的，弟兄们传说他很怕热。\n" }),
 "ha" : ({ "嗯...哈将军是个热情如火却很邋塌的人..弟兄们传说他很怕冷。\n" }),
 "indra" : ({ "嗯...那个雷神之子啊...是个有名的色狼巫师。\n" }),
 "stasia" : ({ "嗯...小雅是个美女...虽然大家都说她身材不是很好...我上次见到她时仔细\n"
               "看了一下，其实也不差嘛。\n" }),
 "ruby" : ({ "嗯...茹比我见过几次...他是个好人....\n"  }),
 "fos" : ({ "嗯...Fos是有名的花花公子...女生看到他是要小心......\n"
            "不过他看起来应该会是个好丈夫。\n"  })
      ]) );
}
