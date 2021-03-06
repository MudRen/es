
#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("少林内功\心法房");
	set_long( @LONG_DESCRIPTION
你现在到了罗汉堂的内功\心法房。请记住内功\是武学之首，内功\差一切都免谈。
少林的初级内功\是『少林基础心法』，请参考门後的破纸上的说明(broken_paper)。   
少林的次级内功\是『少林罗汉心法』，你需要有『初级武僧』以上的实力才能来学。
角落放了一本薄薄的破书(broken_book)，记录了少林罗汉心法，你不妨去看看···  
向下回到精武房，北边是少林朝阳心法房，向上通往少林七十二绝技练功\房。
LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "broken_paper":@PAPER
墙後草草的写了几个字...
『少林基础心法』  
你可以用(study basic) 学到此内功\心法。
注意∶还要练好基本内力技巧才会有内力  
PAPER
         ,"broken_book":@BOOK
书皮上写著『少林罗汉心法』  
只要大叫『万能的天神 请赐给我神奇的力量』(god help) 你将会学到此内功\心法。
注意∶内力值大小和 [所习心法] 及 [基本内功\] 有关 
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"north" : SAULIN"inner_room1",
		"down" : SAULIN"gonfu_room3",
		"up" : SAULIN"72" ]) );
	reset();
}

void init()
{
 add_action("to_study","god");
 add_action("basic","study");
}



int basic(string arg)
{
  string class;

  class=(string)this_player()->query("class");
  if ( !arg || arg!="basic") return 0;
  else if ( class !="monk"){
     write("抱歉你不是本公会的人所以你不能学此心法\n");
     return 1;
                           }
 
        else if ((int)this_player()->query("force_effect")>=1){
write(
" 一个在一旁练功\的和尚看看你，大声的笑道 \n 
『你是白痴啊! 你已经学过基础心法或更好的心法了啦!!! 还闹!』\n\n" );
          return 1;
                                                              }       
        else {
write(
"\n\n 你看见书中发出一道光芒照耀著你 \n");

call_out("idle_teme",10); 
write("一个很柔和的声音说道...... \n

        欢迎加入少林和尚斩妖除魔的行列
        基础心法只是很基本的心法，希望它对你有所助益 \n\n"); 
        this_player()->set("force_effect",1);
        return 1;  
             } 

}

int to_study(string arg)
{
  string class;
  int level;

  level=(int)this_player()->query_level(); 
  class=(string)this_player()->query("class");
  if ( !arg || arg!="help") return 0;
  else if ( class !="monk"){
     write("抱歉你不是本公会的人所以你不能学此心法\n");
     return 1;
                           }
    else if (level<4){
    write("『天神说: 小老弟啊!!! 方丈说得有初级武僧以上的实力才能教授心法啦!』\n\n");
         return 1;
                     } 
        else if ((int)this_player()->query("force_effect")>=2){
write(
" 神累了一天，又被你吵的不能睡觉... 他很不爽的看著你骂道\n 
『你是白痴啊! 你已经学过心法了不能再学啦!!!』\n\n" );
return 1;
                                                              }       
        else {

call_out( "idle_time",5);
write(
"\n\n突然天上一声大吼...... \n");
call_out("idle_time",10);
write(" 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    
@@@ 降龙罗汉法身乍现，你终於领悟到少林罗汉心法的奥义 @@@ 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n" );
        this_player()->set("force_effect",2);
        return 1;  
             } 
}

 
void idle_time()
{
write(" \n");
}
 


