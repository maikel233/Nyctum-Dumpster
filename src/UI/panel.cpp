#include "panel.h"


Panel::Panel ()
{
}


Panel::Panel (Vector2D position) : Panel ()
{
	this->position = position;
}

Panel::Panel (Vector2D position, Vector2D size) : Panel (position)
{
	this->size = size;
}


Panel::Panel (Vector2D position, Vector2D size, Color backgroundColor) : Panel (position, size)
{
	this->backGroundColor = backgroundColor;
}


void Panel::AddComponent (Component* component)
{
	childComponents.push_back (component);
}

void Panel::RemoveComponent (Component* component)
{
	childComponents.erase (std::remove(childComponents.begin(), childComponents.end(), component));
}

void Panel::Draw ()
{
	this->Clear (backGroundColor);
	
	
	for (int i = 0; i < childComponents.size(); i++)
	{
		Component* childComponent = childComponents[i];
		
		// Update the childs context
		childComponent->context = this->context + childComponent->position;
		
		// Draw the component
		childComponent->Draw ();
	}
}