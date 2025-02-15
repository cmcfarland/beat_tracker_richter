#ifndef PLOT_H
#define PLOT_H


class GraphPoint
{
public:
    GraphPoint(float xValue, float yValue);

public:
    float xValue;
    float yValue;
    LinkedListPointer<GraphPoint> nextListItem;
};


class GraphDataset
{
public:
    GraphDataset(String label = "Dataset", Colour colour = Colours::black);

    ~GraphDataset();

    void append(GraphPoint* point);

    String label;
    Colour colour;
    LinkedListPointer<GraphPoint>* points;
    LinkedListPointer<GraphDataset> nextListItem;
};


class Graph
{
public:
    Graph(Rectangle<int> region, String title = "Araz Graph", String xLabel = "X-Axis", 
        String yLabel = "Y-Axis", Colour fgColour = Colours::black, Colour bgColour = Colour(0xffe2e1e0));

    ~Graph();

    void append(GraphDataset* dataset);
    void paint(Graphics& g);

private:
    Rectangle<int> region;
    Rectangle<int> regionGraph;
    String title;
    String xLabel;
    String yLabel;
    Colour fgColour;
    Colour bgColour;
	int xMargin;
	int yMargin;
	LinkedListPointer<GraphDataset>* datasets;
};

#endif
