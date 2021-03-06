#include "../tsunami.h"
#include "/include/move.h"

inherit ROOM;

int radish;

void create()
{
    ::create();
    set_short("『八哩八哩农场』的仓库");
    set_long(@LONG
这里是『八哩八哩农场』的仓库，里头堆放了半人马族近几年的收成；当然，
其中有不少是准备要交给魔族当税捐的。这些年来魔族战祸连绵，需要大量的战备
粮食，因此大幅提高半人马族粮食捐；半人马族心中虽不满，但是由於毫无战力，
所以只能默默屈服。
LONG
            );
    set("light",1);
    set("exits",([
        "east":CITY"farm5"]) );
    set("objects",([
        "wife":TMOB"wife"]) );
    reset();
}

void init()
{
    add_action("do_search","search");
}
    
void reset()
{
    ::reset();
    radish = 3;
}

int do_search(string str)
{
    if( !str || str !="there"){
        if(present("farmer's wife")){
        write("你要死啦，跟你说那边了啊你还给我乱翻.....那边啦！！\n");
        return 1;
        }
        write("一只小老鼠在那边咬著红红的东东，好像就是你要找的耶！\n");
        return 1;
    }
    if( radish == 0){
    write("你找来找去，还是找不到那该死的萝卜，一定是被人拿光了！\n");
    return 1;
    }
    else{
    write("\n为了那该死的萝卜，你一个箱子一个箱子的检查，终於 ....\n.\n.\n不\n行\n了...\n\n");
    tell_room( environment(this_player()),
       this_player()->query("c_name")+"为了找一根萝卜，竟然累的睡著了！\n",
       this_player() );
    this_player()->set_temp("block_command",1);
    call_out("get_radish",5,this_player());
    return 1;
    }
}

int get_radish(object me)
{    
    tell_object(me,@BLONG
隐隐约约你听到有人在唱歌：........................
          嘿呦嘿呦拔萝卜，嘿呦嘿呦拔萝卜
仔细一看，原来是你在拔萝卜啦；由於你求胜心切，不屈不挠，终於把它拔起来了！
你抱著这只大萝卜，心中觉得好满足喔！！
一时熊熊忽然间，萝卜越变越大，大得快要把你压扁了，
你拼命挣扎，努力挣扎，还是没用，心想：糟了，要去远风镇了...........
BLONG
         );
    call_out("wake",7,me);
    return 1;
}

int wake(object me)
{
	object ob;
   ob=new(TOBJ"radish");
   
   tell_object(me,"\n\n你被这恶梦吓得惊醒了，正庆幸还好只是做梦时，赫然看到手中握著一只萝卜......\n\n\n");
   me->set_temp("block_command",0);
   ob->set("owner",(string)me->query("name"));
   ob->move(me);
   tell_room( environment(me),
     "你看到"+me->query("c_name")+"突然惊醒，并望著手中的萝卜发呆！\n"
     , me );
   radish = radish - 1;
   return 1;
}                  
