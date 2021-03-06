
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short("The church of dwarf village","矮人村落的教堂");
  set_long(@Long
一股祥和的气氛笼罩著整个地方,教堂里到处都是虔诚的信徒,矮人的信仰十分
虔诚,期望他们的大神能够解救他们脱离苦海,因此在这里又建造了这座雄伟的大教
堂.教堂内\的\摆\设除了一座非常巨大的神像(statue)外,神像前有一个祭坛(altar),
此外数张长椅被整齐排列著,好让信徒们能专心的祈祷(pray).
Long
);
set("exits",([
    "north":Deathland"/village/v41",
             ]));
set("c_item_desc",([
    "altar":@Altar
一个奇怪的祭坛,上面空无一物.
Altar
    ,"statue":@Statue
巨大的神像耸立在你的面前,似乎你曾经见过他,仔细想一想在小时候的恶梦之
中常常出现的大魔神就是这般模样,他就是传说中的恶神 Evil Yang.他的右手
拿著一把三叉戟 ( trident ) ,指向遥远的西方.善神 Echo 所住的地方.
Statue
    ]) );
set("objects",([
    "believer#1":Monster"/believer",
    "believer#2":Monster"/believer",
    "priest":Monster"/archbishop",
             ]) );
::reset();
}

void init()
{
	add_action("do_pray","pray");
}
int do_pray()
{
	tell_object(this_player(),"你专心的向恶神 Yang 祈祷 ...\n");
	this_player()->save_me();
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}
