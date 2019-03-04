
#include "../echobomber.h"

inherit ROOM;

int be_searched;
void create()
{
	::create();
    set_short("矮人村落的会议室");
    set_long(
@CLong
一间长满蜘蛛网的会议室,灰尘的厚度大概可以留下你完整的脚印\或\手印,由於
这矮人村落已经和和平平地渡过数百年,因此矮人们开会的兴趣也不高,除了每二十
年的例行会议外,这地方几乎没有人会进来闲晃.
CLong
    );
    set("search_desc",([
        "here":"@@to_search_here",
        ]) );
    set("exits",([
                "west":Deathland"/village/v52",
             ]));
    reset();
}
string to_search_here()
{
   object *items,ob1;
   int i;
   
   if ( be_searched==1 ) return 
       "似乎已经有人把这里翻箱倒柜地彻底搜查一遍了.\n";
   items=all_inventory(this_player());
   for(i=0;i<sizeof(items);i++) 
      if ((string)items[i]->query("name")=="broom") {
        ob1=new(Object"/key03");
        ob1->move(this_object());
        be_searched=1;
        this_player()->set_explore("deathland#9");
        return "当你一边清扫,一边找寻的时候,一把黑灰色的"
        "钥匙赫然出现在你的面前.\n";
        }
   return 
     "这里的灰尘很厚,\或\许\一边拿著扫把一边寻找会好一点.\n";  

}
void reset()
{
   ::reset();
   be_searched=0;
}
