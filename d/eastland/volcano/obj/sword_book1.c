#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "mar_short book", "楚辞剑法" );
	set_short( "楚辞剑法" );
	set("long",@LONG
楚辞剑法的剑谱。你能读懂它(read mar_short book)吗?
LONG);
	set( "unit", "本" );
	set( "weight", 1 );
	set( "no_sale", 1 );
        set( "prevent_drop",1);
        set( "prevent_insert",1);  
}

void init()
{
        add_action( "do_read","read");
        add_action( "do_learn", "learn" );
}

int do_read(string arg)
{
  if( !arg || arg!="mar_short book" )
    return 0;
  tell_object(this_player(),@LONG
你翻开剑谱的第一张，上面写道
『楚辞剑法是一种短刃型剑法，强调近身搏斗时的技巧，所以当你的对手所使用的武
器攻击距离越短的，你所能发挥剑法的威力也越大。............................
................................................................』
再继续翻下去就是一些舞剑的图形了，你想，或许你能尝试去学习(learn mar_short
 book)这套剑法。  
LONG);
  return 1;
}

void learn_book(object me,object obj)
{
  tell_object(me,     
 "经过一番苦练，你终於学会楚辞剑法。\n你可以用<enhant mar_short>来施展剑法。\n");
  this_player()->set("scholar_gonfu/mar_short",1);
  obj->remove();
  return;
}

int do_learn(string arg)
{
   object me;
   me=this_player();
   if( !arg || arg!="mar_short book" )
     return 0;
   if (!(me->query("class")=="scholar"))
     return notify_fail("你拿起秘笈仔细端详一番，心想还是放弃好了。\n");
   if ((me->query_skill("palaeography")< 75))
     return notify_fail("你看了半天，连一个字都看不懂。\n");
   if ((me->query_perm_stat("int")< 24))
     return notify_fail("你看了半天，好像有点懂了，但却没有办法理解剑法的精髓。\n");
   if (me->query("scholar_gonfu/mar_short"))
     return notify_fail("你早就了解楚辞剑法的精义了。\n");
   tell_object(me,
     "你仔细研读了一番，突然心领神会，对空比划了起来......\n..............\n\n");
   call_out("learn_book",5,me,this_object());  
   return 1;
}
