#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "半空中" );
	set_long(
	"你正在半空中，不停的向下坠落，往脚下看去，无边的黑暗正如巨兽\n"
	"张开大嘴向你迎面而来，你意识到这对你来说，可能是一个悲惨的结束\n"
	);
        set( "no_monster",1);
        set( "pre_exit_func", ([
                "down" : "check_fall"
        ])) ;        
        set( "exits", ([
                "down" : TROOM"jail1"
        ]) );
}
int recover(object player)
{
write ("\n你终於回复神志，张开眼睛 ...\n\n");
player->set_temp("block_command",0);
player->move_player( TROOM"jail1","SNEAK");
tell_room(TROOM"jail1",
"你看到一个人从天而降，跌到了地牢里，你觉得不那麽寂寞了.......\n",player);
return 1;
}
int check_fall()
{
write(
"\n你不停的向漆黑的空间落去，突然碰的一声巨响，你终於落到了地面。巨大的\n"
"撞击不但使你受了重伤，还使你瘫痪在地，无法动弹......\n\n");
this_player()->set_temp("block_command",1);
call_out("recover",40,this_player());
this_player()->add("hit_points",-(int)this_player()->query("hit_points")/3);
return 1;
}
int clean_up() { return 0; }