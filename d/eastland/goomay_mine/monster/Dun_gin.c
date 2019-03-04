
#include <../zeus.h>
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "dun gin", "断情" );
        add("id",({"dun","gin"}));
        set_short( "断情");
        set("unit","位");
        set_long( @LONG
断情是一位霸气四溢的人，早年在他行走江湖的时候的震嗫了不少的宵
小，著实令动□不安的江湖平静了一段时间，可是英雄难过美人关由於
上苍的捉弄，他最爱的红颜因他而遭人迁怒，不幸魂归离恨，他在万念
俱灰之际，毅然退出江湖来到段家，斩断一切情丝的纠缠改名－断情．
LONG
        );
        set_perm_stat("str",25 );
        set_perm_stat("dex",24 );
        set_natural_weapon(40, 25, 30);
        set_natural_armor( 60, 20 );
        set( "max_hp",700);
        set( "hit_points",700);
        set ("gender", "male");
        set ("race", "dwarf");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon(ZOBJ"/thunder_blade");
        equip_armor(ZOBJ"/white_robe");
        equip_armor(ZOBJ"/fire_cloak");
        equip_armor(ZOBJ"/six_shoe");

        set("inquiry",([
        
           "net": 
                "这些网子是用来兜住所流下来的木头的，我们所开采的铁矿用木头\n"
                "来运送可省下不少时间，懂吗？\n",     
           "river": 
                "那是我们运木头的管道，如果你不怕死的话，可以下去游游(swim)看．\n",
           "ghost":"@@ask_ghost",
                
      ]));
}
int ask_ghost()
{   if(this_player()->query_temp("ask_ghost")){
    tell_object(this_player(),
@AA

哪里有鬼，我看你一定是亏心事做太多了，大厅的南方是我们段家所设的一
间机关房而已，有什麽好大惊小怪的，只要往南边的墙一推就可以进去了，
去去去，别来烦我．
AA
);
}else{
tell_object(this_player(),
@BB

你不要在这边扰乱人心，我们这里可是很乾净的喔！再乱说小心我ｋ你！！
BB
);
}
return 1 ;
}
   