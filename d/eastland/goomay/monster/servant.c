
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(4);
        set_name( "servant", "皮条" );
        set_short( "皮条");
        set("unit","位");
        set_long(
@C_LONG
你看到一个猥琐的汉子，他约莫三四十来岁，可是看起来却更老，
营养不良的脸上还留著纵欲过度的痕迹，一双水泡眼却盯著每个过往
的人，看到那些比较老实或是有点意思的游客就上前一阵乱扯，口里
还嘟囔著好些不三不四的话，当真恬不知耻。
C_LONG
);
        set("alignment",-350);
		set("wu_appear",0);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",8);
        set_perm_stat("kar",6); 
        set_natural_weapon(5,4,9);
        set ("natural_armor_class", 25);
        set_skill("dodge",45);
		set( "defense_type","dodge");
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "human");
        set_c_verbs(({"%s用双手向%s乱抓",
                      "%s用脚向%s乱踢",
                      "%s用头向%s撞去"}));
       
        set( "inquiry", ([
                "wu" : "@@ask_wu"]));
	
}
int appear_wu(object who)
{
	object ob;
	tell_room( environment(), 
	"一个提著一只大茶壶的矮小汉子，一晃一晃的走了过来 ...\n" ,
	who );
        new(Mob"servant_wu" )->move( environment() );
	return 1;
}
int ask_wu()
{
if ( query("wu_appear") ) {
tell_object(this_player(),
@C_WUA
那皮条的一对眼睛很无礼的上下打量你，他邪邪的笑道：「别猴急嘛 !! 
已经帮你叫了，呐～～那不是来了吗？嘻嘻嘻嘻 ～～～
C_WUA
);
return 1;
}

tell_object(this_player(),
@C_WU
那皮条的一对眼睛很无礼的上下打量你，他邪邪的笑道：「来到怡红院不找
姑娘，却要找一个提大茶壶的王八，嘿嘿 !! 」接著他提起嗓子用他职业性
的大嗓门大喊：「王八老吴 ～～　见客啦 ～～」所有人都轰然大笑。
C_WU
);
	set("wu_appear",1);
        call_out("appear_wu", 5,this_object());
        return 1;
}
