
#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("少林朝阳心法房");
	set_long( @LONG_DESCRIPTION
这房间的神桌上供著一尊地藏王菩萨的塑像，屋内洋溢著一股和善庄严的气氛。
如果你学会了罗汉心法而且天资聪敏、多行善事而成为一代大侠的话，你便能在此地
学得少林的另外一套心法『少林朝阳心法』。至於其它更强的心法嘛，就看你的福气 
和机运了。墙上画了一幅幅的经脉人形(shape)，你不妨去看看。
往南通往少林内功\心法房。
LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "shape":@BOOK
墙上写著『少林朝阳心法』但经脉和人形都已剥落不明了，你也看不懂其上的梵文  
怎麽办呢? 心诚则灵，也许\该试试向地藏王祈祷(pray god) 看看他会不会显显灵。

注意∶内力值大小和 [所习心法] 及 [基本内功\] 有关 
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : SAULIN"inner_room" ]) );
	reset();
}

void init()
{
 add_action("to_study","pray");
}

int to_study(string arg)
{
  string class;
  int alignment,effect,inte;

  inte=(int)this_player()->query_stat("int"); 
  effect=(int)this_player()->query("force_effect"); 
  alignment=(int)this_player()->query("alignment"); 
  class=(string)this_player()->query("class");

  if ( !arg || arg!="god") return 0;

  else if ( class !="monk") {
     tell_object(this_player(),"抱歉你不是本公会的人所以你不能学此心法\n");
     return 1;
                            }
  else if (effect>=3) {
tell_object(this_player(),
" 你看见地藏王在瞪你，似乎要骂你贪心，你马上改口说\n 
『菩萨啊，我是来感谢您教导我『朝阳心法』的，不是想再多学些什麽的啦!!!』
  你谄媚的向他一笑，地藏王听完差点从供桌上摔下来...\n\n " );
          return 1;
                    }       
  else if (effect<2) {
tell_object(this_player(),
" 一个老和尚经过你身边，摇了摇头说\n 
『连罗汉心法都不会的人还想学朝阳心法，唉... 人心不足蛇吞象啊!』\n\n " );
          return 1;
                    }       
else if (inte<=8) {
tell_object(this_player(),
"\n一个小沙弥跑出来问你: 
『一加一等於几? 哇!!! 连这个都不知道! 你现在还是太笨了，别想学啦!』\n\n");
         return 1;
                  } 
else if (alignment<5000) {
tell_object(this_player(),
" 一个金甲神从墙上跳了出来，大脚将你踢出门外去  
『朝阳神功\只传给一代大侠，就凭你也配学!!!』 \n\n" );
this_player()->move_player( SAULIN"inner_room","SNEAK");
          return 1;
                                 }       
   else      {

	this_player()->set_temp("chutan", 1 );
    if( !wizardp( this_player() ) ) {
	  this_player()->set_temp("block_command", 1 );
	}
	  this_player()->set_temp("chutaning", 1 );

 tell_object(this_player(),"你突然觉得好累，不觉昏沉沉的睡著了......
 
ＺＺＺｚｚｚｚｚ.... \n\n\n\n\n\n" ); 
 call_out("appear_old",5,this_player());
        return 1;  
             } 
}


void appear_old(object player)
 {
tell_object(player,@APPEAR
突然你看见一个白发老公公走了过来，他摸摸他的长须笑著对你说 :
「嗯，阁下又聪明又有一颗好心肠，我就传你朝阳心法吧! 盼你多行善事!
 造福世人! 切记 切记!!!」


你忽见大地一片光明，老公公全身被阳光笼罩著... 一篇篇心法大要，突然
出现在你的脑海... 你不禁欣喜若狂，跪下谢谢老公公，而後迅速打坐练功
，习颂起少林朝阳心法。
APPEAR
	);
player->set("force_effect",3);
call_out("wake_up",25,player);
 }
void wake_up(object player)
 {
 tell_object(player,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n『懒...猪.猪..啊!!! 起.起...床..啦.!!! 偶..偶.要..扫.地..了....啦』
  一个口吃的扫地僧用扫把柄敲著你的头。 

  你发现你全身都是口水，但却充满了力气，你的内功\修为似忽增进不少...
  抬头一看，你发现地藏王的样子和老公公好像啊，它似乎也在对你微笑著...
  你心满意足的站了起来 \n\n");
	player->set_temp("chutan", 0 );
    if( !wizardp( player ) ) {
	  player->set_temp("block_command", 0 );
	}
	  player->set_temp("chutaning", 0 );
}


