	set( "equip_func", "angel" );



void angel()
{
string name; 
object holder;

 holder = environment(this_object());
 name=(string)holder->query("name");
 if (name!="angel") {

     tell_object( holder, can_read_chinese(holder)?
     "\n\n衣服突然射出一阵光芒，它似乎不愿臣服於你，蹦的一声大力的打了你一下
你受到严重的伤害。\n"
        this_object()->move(environment(environment(this_object())) );
                   }
       else {

    tell_object( holder, can_read_chinese(holder)?
 bold("\n『我服从陛下的领导，请带领我去屠杀世间的生灵吧!!!』衣服传来一阵狂笑
『但是别忘了，要加油啊!』你发现你的手掌流出大量的鲜血...\n"):
         "\nThe sword obeyb your control.\n" );
	holder->receive_damage(40);
            }   
}

