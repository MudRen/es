#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("马房");
  set_long( @CLong
这儿是牧马关的马房，饲养著远近驰名的牧马关战马。由於牧马关的马儿们战绩辉
煌，所以在马房里也十分受到礼遇。这儿打扫得乾净舒适，可能比士兵住得还服舒些。
西北边有条小路通往教场。
CLong
);
set_outside("eastland");
set("exits",([
               "northwest":MUMAR"square03",
             ]));
 
set( "pre_exit_func", ([ "northwest" : "can_pass" ]) );
set("objects",([
               "groom":MOB"groom",
               "horse#1":MOB"horse",
               "horse#2":MOB"horse"]));
reset();
}
 
int can_pass()
{ if(this_player()->query_temp("mounting") && !wizardp(this_player()) &&
       present("groom") )
   {  if(this_player()->query_temp("cavalry_mark") )  {
           tell_object(this_player(),
                       "马夫轻声地对你说道：长官，您请慢走!\n" );
           this_player()->set_temp("cavalry_mark",0) ;
           return 0;
             }
      else   {
      tell_object(this_player(),
"马夫狠狠地瞪著你说：我最讨厌自以为骑术很好的人却不了解马的人到我这来！\n"
"马夫说话的同时，轻拍著你的座骑，并用一种柔和的语调对马说话。\n"
"你的座骑忽然间有点不听使唤，一步也不肯动...\n" );
      return 1;
             }
   }
else
    return 0;
}
