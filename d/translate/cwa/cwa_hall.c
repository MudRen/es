#include <mudlib.h> 

inherit ROOM;

void create()
{
	::create();
	set_short("Color Wolf Association", "色狼协会" );
	set_long(
"You are in the great hall of Color Wolf Association.\n",
      "这□是色狼协会大厅, 你看到猪八戒亲切地对你微笑. 但是千万\n"
"不要想杀猪八戒来赚经验点, 否则总有一天你会受到狼群围攻, 死无葬\n"
"身之地!\n"
      "你可在这□加入色狼协会, 不过你最好先看看东边墙上的说明公\n"
"告(sign)再说. 西边的墙上则是一个英雄榜(list), 上面有所有色狼协\n"
"会成员的名单.\n"
	);
	set( "light",1 );
	set( "exits", ([
		"up" : "/u/s/supertramp/cwa/cwa_club"
	]) );
	set("pre_exit_func", ([
		"up" : "check_color"
	]) );
	set("item_desc", ([
		"sign" : @SIGN
===============================================================
===============================================================
SIGN
	])  );

	set("c_item_desc", ([
		"sign" : @C_SIGN
==============================================================
  色狼协会是诺顿大地历史最悠久, 成员最多的组织. 它的会员们各
  各都具有超人的能力, 姣好的面孔, 天才的智商以及最重要的 - 
  超凡入圣的品德. 若你(你)亦具备了上述优良的特质, 现在就加入
  神圣的色狼协会吧!
==============================================================
C_SIGN
	])  );

	set("item_func",([
		"list" : "look_list"
	]));

	set("objects", ([
		"pig8" : "/u/s/supertramp/cwa/pig"  ]));
}

int look_list() {
	cat("/u/s/supertramp/cwa/memberlist.txt");
	return(1);
}

void init()
{
        add_action("join","join");
}

int join()
{
	if((int)this_player()->query("CWA")==1)
		return notify_fail(can_read_chinese()?
"你早已加入色狼协会了!\n" :
"You are already a member of CWA!\n");

	write(can_read_chinese()?
"你以为神圣的色狼协会是那麽好加入吗? 别傻了!\n" +
"色狼协会会员们都是东方故事中的精英! 你认为你\n" +
"够资格吗? 如果你真的认为你自己行, 送封信给协\n" +
"会中的任何一位长老, 他们将尽快审定你的入会资\n" +
"格! 祝好运!" :     
"Do you think it's THAT EASY to join CWA? Don't be silly!\n" +
"Send a mail to the elders in CWA first, they will decide if\n" +
"you can join or not. Send them a mail NOW!\n");
	return(1);
} 


int check_color()  {
	if((int)this_player()->query("CWA")!=1)  {
		write(can_read_chinese()?
"\n\n\n猪八戒大声喝道：慢著, 小子! 你以为你是谁? 你给我站住!\n\n\n\n"+
"你从惊吓中回过神来, 但再也不敢冒犯猪八戒及任何色狼协会会员了\n" :
"\n\n\nThe evil pig shouts: Stop! Kid! Who do you think you are? FREEZE!\n\n\n\n"+
"You awake, but you are now afraid of the evil pig and CWA members very much!\n"); 
		return(1);
	}
	return(0);
}


