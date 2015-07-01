/*! \file animationactions.h
	\author HiddenSeeker

	Describes a group of actions, linked to animations
 */
#pragma once
#include <QObject>
#include <QRectF>

#include <sadhash.h>
#include <animations/animationscomposite.h>

class MainPanel;

namespace gui
{

class AnimationProcess;

/*! A group of actions, linked to animations
 */	
class AnimationActions: public QObject
{
Q_OBJECT
public:
	/*! Creates new label actions
		\param[in] parent a parent object
	 */
	AnimationActions(QObject* parent = NULL);
	/*! This class could be inherited
	 */
	virtual ~AnimationActions();
	/*! Sets panel, where actions belong to
		\param[in] e main panel
	 */
	void setPanel(MainPanel* e);
	/*! Returns panel, where actions belong to
	 */
	MainPanel* panel() const;
	/*! Returns true if adding second animation into children of first produces loop
		\param[in] first first loop
		\param[in] second second loop
	 */
	bool producesLoop(sad::animations::Animation* first, sad::animations::Animation* second);
	/*! Returns true if adding second animation into children of first produces loop
		\param[in] current current visited animation
		\param[in] visited set of visited noded
		\param[in] first a first visited part
		\param[in] second a second visited part
	 */
	static bool producesLoop(
		sad::animations::Composite* current,
		const sad::Hash<unsigned long long, unsigned long long>& visited,
		sad::animations::Animation* first,
		sad::animations::Animation* second
	);
	/*! Removes an animation from database
		\param[in] a animation
		\param[in] fromeditor whether it's being removed from editor
 	 */
	void removeAnimationFromDatabase(
		sad::animations::Animation* a,
		bool fromeditor
	);
	/*! Adds animation to composite list
		\param[in] a composite list
		\param[in] addedanimation an added animation
		\param[in] fromeditor whether it's being added to a list
	 */
	bool addAnimationToCompositeList(
		sad::animations::Composite* a,
		sad::animations::Animation* addedanimation,
		bool fromeditor
	);
	/*! Removes animation from composite list
		\param[in] a composite list
		\param[in] addedanimation an added animation
		\param[in] fromeditor whether it's being added to a list
		\param[in] row a row (-1 if undefined)
	 */
	bool removeAnimationFromCompositeList(
		sad::animations::Composite* a,
		sad::animations::Animation* addedanimation,
		bool fromeditor,
		int row = -1
	);
public slots:
	/*! Tries to add new animation to a list
	 */
	void addAnimation();
	/*! Triews to remove animation from all related list
	 */
	void removeAnimation();
	/*! Called, when user changes animation in list
		\param[in] row a new selected row in list
	 */
	void currentAnimationChanged(int row);
	/*! Called, when user changes name of animation
		\param[in] name a name of animation
	 */
	void nameChanged(const QString& name);
	/*! Called, when user changes time of animation
		\param[in] time a time of animation
	 */
	void timeChanged(double time);
	/*! Called, when user changes "Whether animation is looped" flag
		\param[in] newvalue a new value
	 */
	void loopedChanged(bool newvalue);
	/*! Called, when user changes frequency of blinking of animation
		\param[in] nvalue a value
	 */
	void blinkingFrequencyChanged(int nvalue);
	/*! Starts a selected animation as instance on selected object
	 */
	void startOnObject();
	/*! Stops a selected animation as instance on selected object
	 */
	void stopOnObject();
	/*! Changes starting color for color animations
	 */
	void colorChangeStartingColor();
	/*! Changes ending color for color animations
	 */
	void colorChangeEndingColor();
	/*! Called, when user changes x coordinate of starting size for Resize type of animation
		for X coordinate
		\param[in] newvalue a new value
	 */
	void resizeChangeStartingSizeX(double newvalue);
	/*! Called, when user changes y coordinate of starting size for Resize type of animation
		for Y coordinate
		\param[in] newvalue a new value
	 */
	void resizeChangeStartingSizeY(double newvalue);
	/*! Called, when user changes x coordinate of ending size for Resize type of animation
		for X coordinate
		\param[in] newvalue a new value
	 */
	void resizeChangeEndingSizeX(double newvalue);
	/*! Called, when user changes y coordinate of ending size for Resize type of animation
		for Y coordinate
		\param[in] newvalue a new value
	 */
	void resizeChangeEndingSizeY(double newvalue);
	/*! Called, when user changes starting angle for rotation angle
		\param[in] newvalue new value for angle
	 */ 
	void rotateChangeStartingAngle(double newvalue);
	/*! Called, when user changes ending angle for rotation angle
		\param[in] newvalue new value for angle
	 */ 
	void rotateChangeEndingAngle(double newvalue);
	/*! Called, when user changes way for way moving animation
		\param[in] row a row
	 */
	void wayMovingChangeWay(int row);
	/*! Called, when font list editing  finished (timed event, see implementation of
		gui::textedit::TextEdit for detail)
	 */
	void fontListEditingFinished();
	/*! Called, when font size starting size changed
		\param[in] newvalue new value
	 */
	void fontSizeChangeStartingSize(int newvalue);
	/*! Called, when font size ending size changed
		\param[in] newvalue new value
	 */
	void fontSizeChangeEndingSize(int newvalue);
	/*! Called, when option list editing  finished (timed event, see implementation of
		gui::textedit::TextEdit for detail)
	 */
	void optionListEditingFinished();
	/*! Called, when texture coordinates list editing  finished (timed event, see implementation of
		gui::textedit::TextEdit for detail)
	 */
	void textureCoordinatesListEditingFinished();
	/*! Called, when user changes starting rect for a value
		\param[in] value new value
	 */
	void textureCoordinatesChangeStartRect(QRectF value);
	/*! Called, when user changes ending rect for a value
		\param[in] value new value
	 */
	void textureCoordinatesChangeEndRect(QRectF value);
	/*! Called, when user changes x coordinate of camera rotation pivot 
		\param[in] newx new value
	 */
	void cameraRotationChangePivotX(double newx);
	/*! Called, when user changes y coordinate of camera rotation pivot 
		\param[in] newy new value
	 */
	void cameraRotationChangePivotY(double newy);
	/*! Called, when user changes starting angle of camera rotation animation
		\param[in] newvalue a new value for animation
	 */
	void cameraRotationChangeStartingAngle(double newvalue);
	/*! Called, when user changes ending angle of camera rotation animation
		\param[in] newvalue a new value for animation
	 */
	void cameraRotationChangeEndingAngle(double newvalue);
	/*! Called, when user changes x coordinate of camera shaking offset 
		\param[in] newx new value
	 */
	void cameraShakingChangeOffsetX(double newx);
	/*! Called, when user changes y coordinate of camera shaking offset
		\param[in] newy new value
	 */
	void cameraShakingChangeOffsetY(double newy);
	/*! Called, when user changes frequency of camera shaking
		\param[in] newvalue a new value
	 */
	void cameraShakingChangeFrequency(int newvalue);
	/*! Update composite elements list
	 */
	void updateCompositeList();
	/*! Adds animation to composite animations list
	 */
	void addAnimationToComposite();
	/*! Removes animation from composite animations list
	 */
	void removeAnimationFromComposite();
	/*! Moves animation back in composite list
	 */
	void moveBackInCompositeList();
	/*! Moves animation front in composite list
	 */
	void moveFrontInCompositeList();
    /*! Called, when user changes x coordinates of starting point for simple
        movement animation type
       \param[in] newvalue a new value
     */
    void simpleMovementChangeStartingPointX(double newvalue);
    /*! Called, when user changes y coordinates of starting point for simple
        movement animation type
       \param[in] newvalue a new value
     */
    void simpleMovementChangeStartingPointY(double newvalue);
    /*! Called, when user changes x coordinates of ending point for simple
        movement animation type
       \param[in] newvalue a new value
     */
    void simpleMovementChangeEndingPointX(double newvalue);
    /*! Called, when user changes y coordinates of ending point for simple
        movement animation type
       \param[in] newvalue a new value
     */
    void simpleMovementChangeEndingPointY(double newvalue);
private:
	/*! An panel, which actions are belong to
	 */
	MainPanel* m_panel;
	/*! A running animation process 
	 */
	gui::AnimationProcess* m_animation;
};

}
